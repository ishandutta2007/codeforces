#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

#define X first
#define Y second

const int alp=27;
const int inf=1e9+10;
const int N=1e6+10;

int n,test,pa[N][20];
vector <int> v[N];
int f[N][20];
int q[N],depth[N];

void prepare(){
    scanf("%d%d",&n,&test);
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
}


void BFS(){
    int top=1,bot=1;
    q[1]=1;
    while (top<=bot){
        int x=q[top++];
        for(auto y:v[x]) if (y!=pa[x][0]){
            pa[y][0]=x;
            q[++bot]=y;
        }
    }
}
ii minpath(int x,int y){
    if (depth[x]<depth[y]) swap(x,y);
    int ansval=n+1;
    for(int i=0,val=depth[x]-depth[y];val;i++,val>>=1) if (val&1){
        ansval=min(ansval,f[x][i]);
        x=pa[x][i];
    }
    if (x==y) return ii(x,min(ansval,x));
    for(int i=int(log2(depth[x]));i>=0;i--) if (pa[x][i]!=pa[y][i]){
        ansval=min(ansval,min(f[x][i],f[y][i]));
        x=pa[x][i];
        y=pa[y][i];
    }
    ansval=min(ansval,min(min(x,y),pa[x][0]));
    return ii(x,ansval);
}

void solve(){
    BFS();
    for(int i=2;i<=n;i++) depth[q[i]]=depth[pa[q[i]][0]]+1;
    for(int i=1;i<=n;i++) f[i][0]=i;
    for(int j=1;j<20;j++)
        for(int i=1;i<=n;i++){
            pa[i][j]=pa[pa[i][j-1]][j-1];
            f[i][j]=min(f[i][j-1],f[pa[i][j-1]][j-1]);
        }


    int lans=0;
    int master=-1,best=n+1;
    while (test--){
        int type,x;
        scanf("%d%d",&type,&x);
        x=(x+lans)%n+1;
        if (type==1){
            if (master==-1) master=best=x;
            else {
                ii cur=minpath(master,x);
//                cout<<master<<" "<<x<<" "<<cur.X<<" "<<cur.Y<<'\n';
                best=min(best,cur.Y);
                master=cur.X;
            }
        }else{
            lans=min(best,minpath(master,x).Y);
            printf("%d\n",lans);
        }
//        cout<<master<<"="<<best<<'\n';
    }
}
int main(){
    prepare();
    solve();
}