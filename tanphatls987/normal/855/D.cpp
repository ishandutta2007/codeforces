#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=1e5+10;
const ll inf=3e18;
const int MOD=1e9+7;

int n;
vector <int> v[N];

int lv[N],f[N][2];
int pa[N][20];


int LCA(int x,int y){

    ///return 0 if no common LCA
    if (lv[x]<lv[y]) swap(x,y);
    for(int i=0,val=lv[x]-lv[y];val;i++,val>>=1)
        if (val&1) x=pa[x][i];
    if (x==y) return x;
    for(int i=int(log2(lv[x]));i>=0;i--)
        if (pa[x][i]!=pa[y][i])
            x=pa[x][i],y=pa[y][i];
    return pa[x][0];
}
void prepare(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int type;
        scanf("%d%d",pa[i],&type);
        if (pa[i][0]==-1) {
            pa[i][0]=0;
            continue;
        }
        for(int j=0;j<=1;j++) f[i][j]=f[pa[i][0]][j]+(j==type);
//        cout<<i<<" "<<type<<" "<<pa[i][0]<<" "<<f[i][0]<<" "<<f[i][1]<<'\n';
        lv[i]=lv[pa[i][0]]+1;
    }
    for(int j=1;j<20;j++)
        for(int i=1;i<=n;i++) pa[i][j]=pa[pa[i][j-1]][j-1];
}

int solve(int type,int x,int y){
    /// Y to X
    int z=LCA(x,y);
    if (z==0) return 0;
    ///same obj
    if (x==y) return 0;
    if (type==1){
        if (z!=x) return 0;
        if (f[y][0]-f[x][0]!=lv[y]-lv[x]) return 0;
        return 1;
    }
    if (type==2){
        if (z==y) return 0;
        if (f[x][0]-f[z][0]!=lv[x]-lv[z]) return 0;
        if (f[y][1]-f[z][1]!=lv[y]-lv[z]) return 0;
        return 1;
    }
}

int main() {
    prepare();
    int test;
    scanf("%d",&test);
    while (test--){
        int type,x,y;
        scanf("%d%d%d",&type,&x,&y);
        if (solve(type,x,y)) printf("yes\n");
        else printf("no\n");
    }
}