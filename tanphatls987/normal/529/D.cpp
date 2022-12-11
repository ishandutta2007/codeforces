#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("d.inp","r",stdin)
#define OUTPUT freopen("d.out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=1e5+10;

int n,M,T,hh,mm,ss,f[N],g[N],h[N],r[N],q[N];
int main(){
    scanf("%d%d%d",&n,&M,&T);
    FOR(i,1,n) {
        scanf("%d:%d:%d",&hh,&mm,&ss);
        //printf("%d %d %d\n",hh,mm,ss);
        h[hh*3600+mm*60+ss]++;
    }
    int ans=0;
    bool ok=false;
    int cur=0,top=0;
    if (M<=0){
        printf("No solution");
        return 0;
    }
    int L=1,R=0;
    REP(i,0,86400){
        while (cur&&g[q[L]]==i)
            g[q[L]]=0,L++,cur--;
        while (h[i]&&cur<M) {
            q[++R]=++ans,g[ans]=i+T;
            f[++top]=ans;
            h[i]--,cur++;
        }
        REP(j,0,h[i]) f[++top]=q[R],g[q[R]]=i+T;
        if (cur==M) ok=true;
    }
    if (!ok){
        printf("No solution");
        return 0;
    }
    printf("%d\n",ans);
    FOR(i,1,n) printf("%d\n",f[i]);
}