#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

#define X first
#define Y second

const int N=1e2+10,M=30;
const int MOD=1e9+7;

int n,k;
vector <int> v[N];
int q[N],pa[N];


int f[N][M][M];
int ftmp[M][M];
void BFS(){
    int top=1,bot=1;
    q[1]=1;
    while (top<=bot){
        int x=q[top++];
        for(auto y:v[x]) if (y!=pa[x]){
            pa[y]=x;
            q[++bot]=y;
        }
    }
}

void prepare(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    BFS();
}

ii merge(int fwx,int cbx,int fwy,int cby){
    ii ans;
    if (fwy+cbx<=k) fwy=0;
    else if (fwy) fwy++;
    if (fwx+cby<=k) fwx=0;
    return ii(max(fwy,fwx),min(cbx,cby+1));
}
int solve(){
    for(int pos=n;pos>=1;pos--){
        int x=q[pos];
        f[x][1][k+1]=1;
        f[x][0][0]=1;
        for(auto y:v[x]) if (y!=pa[x]){
            for(int i=0;i<=k+1;i++)
                for(int j=0;j<=k+1;j++) ftmp[i][j]=f[x][i][j];
            memset(f[x],0,sizeof(f[x]));
            for(int fwy=0;fwy<=k+1;fwy++)
                for(int cby=0;cby<=k+1;cby++)
                    for(int fwx=0;fwx<=k+1;fwx++)
                        for(int cbx=0;cbx<=k+1;cbx++) {
                            ii cur=merge(fwx,cbx,fwy,cby);
                            if (cur.X==-1) continue;
                            f[x][cur.X][cur.Y]=(f[x][cur.X][cur.Y]+1LL*ftmp[fwx][cbx]*f[y][fwy][cby])%MOD;
//                            cout<<fwx<<" "<<cbx<<" "<<fwy<<" "<<cby<<" "<<cur.X<<" "<<cur.Y<<'\n';
                        }

        }
//        for(int fw=0;fw<=k+1;fw++)
//            for(int cb=0;cb<=k+1;cb++) if (f[x][fw][cb]) cout<<x<<" "<<fw<<" "<<cb<<" "<<f[x][fw][cb]<<'\n';
    }
    int ans=0;
    for(int cb=0;cb<=k;cb++) ans=(ans+f[1][0][cb])%MOD;
    return ans;
}
int main(){
    prepare();
    cout<<solve();
}