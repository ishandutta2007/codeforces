#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("e.inp","r",stdin)
#define OUTPUT freopen("e.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,int> lli;

const int inf=1e9;
const int MOD=1e9+7;
const int N=2e6+10;

int n,m,a[30],c=0,h[2];
ll S,fac[20],sum=0,ans=0,f[30];
lli b[2][N];
void DFS(int type,int x){
    bool out=(type&&x==n+1)||(!type&&x==n/2+1);
    if (out){
        b[type][++h[type]]=lli(sum,c);
        return;
    }
    if (a[x]<=18&&sum+fac[a[x]]<=S&&c<m) {
        sum+=fac[a[x]];
        c++;
        DFS(type,x+1);
        sum-=fac[a[x]];
        c--;
    }
    if (sum+a[x]<=S){
        sum+=a[x];
        DFS(type,x+1);
        sum-=a[x];
    }
    DFS(type,x+1);
}
int main(){
    cin>>n>>m>>S;
    fac[0]=1;
    FOR(i,1,19) fac[i]=fac[i-1]*i;
    FOR(i,1,n) cin>>a[i];
    DFS(0,1);
    DFS(1,n/2+1);
    FOR(j,0,1) sort(b[j]+1,b[j]+h[j]+1);
//    FOR(j,0,1){
//        printf("%d\n",h[j]);
//        FOR(i,1,h[j]) cout<<b[j][i].X<<" "<<b[j][i].Y<<'\n';
//    }
    int R=h[1];
    FOR(i1,1,h[0]){
        int j1=i1;
        while (j1<h[0]&&b[0][j1+1].X==b[0][i1].X) j1++;
        while (R>0&&b[1][R].X>S-b[0][i1].X) R--;
        if (R&&b[0][i1].X+b[1][R].X==S){
            int L=R;
            while (L>1&&b[1][L-1].X==b[1][R].X) L--;
            memset(f,0,sizeof(f));
            FOR(i,L,R) f[b[1][i].Y]++;
            FOR(i,1,m) f[i]+=f[i-1];
            FOR(i,i1,j1) ans+=f[m-b[0][i].Y];
        }
        i1=j1;
    }
    cout<<ans;
}