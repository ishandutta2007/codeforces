#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("359.inp","r",stdin)
#define OUTPUT freopen("359.out","w",stdout)
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
const int N=1e5+10;

int n,x,a[N];
ll suf[N],pre[N],s[N];
priority_queue <ll> q;
ll power(ll x,ll y){
    ll ans=1;
    while (y){
        if (y&1) ans=ans*x%MOD;
        x=x*x%MOD;
        y>>=1;
    }
    return ans;
}
ll solve(){
    FOR(i,1,n) pre[i]=pre[i-1]+a[i];
    FORD(i,n,1) suf[i]=suf[i+1]+a[i];
    FOR(i,1,n) q.push(-pre[i-1]-suf[i+1]);
    while (1){
        ll cur=q.top();
        int len=0;
        while (!q.empty()&&q.top()==cur&&len<x) len++,q.pop();
        q.push(cur-(len==x));
        if (len<x) break;
    }
//    cout<<s[top]<<'\n';
    return power(x,min(-q.top(),pre[n]));
}
int main(){
    scanf("%d%d",&n,&x);
    FOR(i,1,n) scanf("%d",a+i);
    cout<<solve();
}