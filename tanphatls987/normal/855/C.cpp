#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=1e5+10;
const ll inf=3e18;
const int MOD=1e9+7;

int n,m,k,need;
vector <int> v[N];

ll f[N][3][12],tmpf[12];

int q[N],pa[N];
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
ll solve(){
    BFS();

    for(int pha=n;pha>=1;pha--){
        int x=q[pha];
        ///type 0
        f[x][0][1]=1;
        for(auto y:v[x]) if (y!=pa[x]){
            memset(tmpf,0,sizeof(tmpf));
            for(int i=0;i<=need;i++)
                for(int j=0;j<=need-i;j++) tmpf[i+j]=(tmpf[i+j]+f[x][0][i]*f[y][1][j])%MOD;
            for(int i=0;i<=need;i++) f[x][0][i]=tmpf[i];
        }
        f[x][1][0]=k-1;
        for(auto y:v[x]) if (y!=pa[x]){
            memset(tmpf,0,sizeof(tmpf));
            for(int i=0;i<=need;i++)
                for(int j=0;j<=need-i;j++) tmpf[i+j]=(tmpf[i+j]+f[x][1][i]*(f[y][0][j]+f[y][1][j]+f[y][2][j]))%MOD;
            for(int i=0;i<=need;i++) f[x][1][i]=tmpf[i];
        }
        f[x][2][0]=m-k;
        for(auto y:v[x]) if (y!=pa[x]){
            memset(tmpf,0,sizeof(tmpf));
            for(int i=0;i<=need;i++)
                for(int j=0;j<=need-i;j++) tmpf[i+j]=(tmpf[i+j]+f[x][2][i]*(f[y][1][j]+f[y][2][j]))%MOD;
            for(int i=0;i<=need;i++) f[x][2][i]=tmpf[i];
        }
    }
    ll ans=0;
    for(int use=0;use<=need;use++)
        for(int i=0;i<3;i++)ans=(ans+f[1][i][use])%MOD;
    return ans;
}
int main() {
    cin>>n>>m;
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    cin>>k>>need;
    cout<<solve();
}