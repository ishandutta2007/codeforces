#include <bits/stdc++.h>
using namespace std;

//Start
typedef long long ll;
typedef double db;
#define mp(a,b) make_pair((a),(b))
#define x first
#define y second
#define be(a) (a).begin()
#define en(a) (a).end()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define R(i,a,b) for(int i=(a),I=(b);i<I;i++)
#define L(i,a,b) for(int i=(a),I=(b);i>I;i--)
const int iinf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;

//Main
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    ll n,r1,r2,r3,d,ans=linf;
    cin>>n>>r1>>r2>>r3>>d;
    vector<ll> a(n),pa(n),st(n);
    R(i,0,n) cin>>a[i],pa[i]=r1*a[i]+r3,st[i]=min(r2,r1*(a[i]+1))+min(min(r1,r2),r3);
    vector<ll> f(n+1,linf),g(n+1); f[0]=d*(n-1);
    R(i,0,n){
        f[i+1]=min(f[i+1],f[i]+pa[i]);
        f[i+1]=min(f[i+1],f[i]+st[i]+d*2);
        if(i+1<n) f[i+2]=min(f[i+2],f[i]+st[i]+st[i+1]+d*2);  
    }
    ans=min(ans,f[n]);
    L(i,n-2,-1) g[i]=g[i+1]+min(pa[i],st[i]);
    R(i,0,n-1){
        ans=min(ans,f[i]+g[i]+d*(n-1-i)+pa[n-1]);
        ans=min(ans,f[i]+g[i]+d*(n-1-i)+d*2+st[n-1]);
    }
    cout<<ans<<'\n';
    return 0;
}