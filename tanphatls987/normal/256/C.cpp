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

const int inf=1e9;
const int MOD=1e9+7;
const ll LIM=777777777777;
const int N=1e2+10;

ll p[N];
int m,h[N],g[N];
priority_queue <ll> q;
ll power(ll x,ll y){
    ll ans=1;
    while (y){
        if (y&1) ans=(LIM/ans>=x)?ans*x:LIM+1;
        y>>=1;
        x=(LIM/x>=x)?x*x:LIM+1;
    }
    return ans;
}
void prepare(){
    p[1]=4;
    m=1;
    for(ll tmp1=1,tmp2=1;p[m]<=LIM;){
        while ((tmp1+1)*(tmp1+1)<=p[m]) tmp1++;
        while (power(tmp2,4)<p[m]) tmp2++;
        int L=upper_bound(p+1,p+m+1,tmp2)-p-1,R=upper_bound(p+1,p+m+1,tmp1)-p-1;
        FOR(i,L,min(R,m-1)) h[g[i]]=m;
        while (h[g[m]]==m) g[m]++;
        p[++m]=min(power(p[R+1],2),power(p[L+1]-1,4)+1);
//        printf("%lld\n",p[m]);
    }
//    cout<<m<<'\n';
//    FOR(i,1,m) cout<<p[i]<<" ";ENDL;
}
int main(){
    prepare();
    int n,ans=0;
    ll x;
    scanf("%d",&n);
    while (n--){
        scanf("%I64d",&x);
        ans^=g[upper_bound(p+1,p+m+1,x)-p-1];
    }
    if (ans) printf("Furlo");
    else printf("Rublo");
}