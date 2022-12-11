#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("d.inp","r",stdin)
#define OUTPUT freopen("d.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=1e6+10;

int p2[N],h[N],n,m,k,x,y;
int main(){
    p2[0]=1;
    scanf("%d%d%d",&n,&m,&k);
    FOR(i,1,n) p2[i]=(p2[i-1]*2)%MOD;
    while (m--){
        scanf("%d%d",&x,&y);
        if (y-x==1) continue;
        if (y-x==k+1) h[x]=1;
        else {
            printf("0");
            return 0;
        }
    }
    int L=0;
    FOR(i,1,n) {
        if (h[i]&&!L) L=i;
        if (i>=k+2&&h[i]&&h[i-k-1]){
            printf("0");
            return 0;
        }
        h[i]+=h[i-1];
    }
    //FOR(i,0,n) cout<<h[i]<<" \n"[i==n];
    int ans=1;
    if (L){
        for(int i=max(1,L-k);i<=min(n-k-1,L+k);i++) if (h[i]==h[i-1]&&h[n]-h[i+k]==0){
            int R=min(min(i,L)+k,n-k-1);
            ans=(ans+p2[R-i-(h[R]-h[i])])%MOD;
            //printf("%d %d %d\n",i,R,ans);
        }
    }else FOR(i,1,n-k-1){
        int R=min(i+k,n-k-1);
        ans=(ans+p2[R-i])%MOD;
    }
    cout<<ans;
}