#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("C.inp","r",stdin)
#define OUTPUT freopen("C.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;
typedef unsigned long long ull;

const int inf=1e9;
const int MOD=1e9+7;
const int N=2e2+5;

int n,a[N],deg[N]={0},h[N]={0},s[N],g[N]={0};
int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i),deg[a[i]]++;
    ll ans=1;
    int small=0;
    FOR(i,1,n) if (!deg[i]&&!g[i]){
        memset(h,0,sizeof(h));
        int top=1;
        s[1]=i;
        h[i]=1;
        g[i]=1;
        while (1){
            int x=a[s[top]];
            if (h[x]){
                small=max(small,h[x]-1);
                ans=ans/__gcd(ans,ll(top-h[x]+1))*(top-h[x]+1);
                break;
            }else s[++top]=x,h[x]=top,g[x]=1;
        }
    }
    FOR(i,1,n) if (!g[i]){
        int top=1;
        s[1]=i;
        g[i]=1;
        while (1){
            int x=a[s[top]];
            if (g[x]){
                int len=top;
                ans=ans/__gcd(ans,ll(len))*len;
                break;
            }else s[++top]=x,g[x]=top;
        }
    }
    ans=ans*max((small+ans-1)/ans,1LL);
    cout<<ans;
}