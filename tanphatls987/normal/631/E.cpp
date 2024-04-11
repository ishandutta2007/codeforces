#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("E.inp","r",stdin)
#define OUTPUT freopen("E.out","w",stdout)
#define FOR(i,l,r) for(auto i=(l);i<=(r);i++)
#define REP(i,l,r) for(auto i=(l);i<(r);i++)
#define FORD(i,l,r) for(auto i=(l);i>=(r);i--)
#define REPD(i,l,r) for(auto i=(l);i>(r);i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;

const int inf=1e9;
const int MOD=1e9+7,scale=1e6+10;
const int N=2e5+10;

int n,a[N],p[N];
ll psum[N];
int q[N];
pll line[N];
ll cal(pll a,ll x){
    return a.X*x+a.Y;
}
bool isLeft(pll piv,pll a,pll b){
    return (b.Y-piv.Y)*(piv.X-a.X)<=(a.Y-piv.Y)*(piv.X-b.X);
}
bool comp(int x,int y){
    return a[x]<a[y];
}
void prepare(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    FOR(i,1,n) a[i]+=scale;
    FOR(i,1,n) psum[i]=psum[i-1]+a[i];
}
ll solve(){
    ll ans=0;
    ///phase 1
    int n1=0;
    FOR(i,1,n) line[i]=pll(i,-psum[i]);
    FOR(i,1,n){
        while (n1>1&&isLeft(line[q[n1-1]],line[q[n1]],line[i])) n1--;
        q[++n1]=i;
    }
    for(int i=1,j=1;i<=n;i++){
        while (q[j]<i) j++;
        int L=j,R=n1-1;
        while (L<=R){
            int mid=(L+R)/2;
            if (cal(line[q[mid]],a[i])<=cal(line[q[mid+1]],a[i])) L=mid+1;
            else R=mid-1;
        }
        ans=max(ans,cal(line[q[L]],a[i])-1LL*a[i]*i+psum[i]);
    }
    ///phase 2
    n1=0;
    FOR(i,1,n) line[i]=pll(i,-psum[i-1]);
    FOR(i,1,n){
        while (n1>1&&isLeft(line[q[n1-1]],line[q[n1]],line[i])) n1--;
        q[++n1]=i;
    }
    for(int i=1,j=1;i<=n;i++){
        while (j<=n1&&q[j]<=i) j++;
        int L=1,R=j-2;
        while (L<=R){
            int mid=(L+R)/2;
            if (cal(line[q[mid]],a[i])<=cal(line[q[mid+1]],a[i])) L=mid+1;
            else R=mid-1;
        }
        ans=max(ans,cal(line[q[L]],a[i])-1LL*a[i]*i+psum[i-1]);
    }
    FOR(i,1,n) ans+=1LL*(a[i]-scale)*i;
    return ans;
}
int main(){
//    freopen("input.inp","r",stdin);
    prepare();
    cout<<solve();
}