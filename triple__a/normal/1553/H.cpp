#include<bits/stdc++.h>
#define int long long

using namespace std;
#define rep(i,n) for (int i=0;i<(int)(n);++i)
#define rep1(i,n) for (int i=1;i<=(int)(n);++i)
#define range(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

// using namespace std;
const int maxn=1<<19;
int n,k;
int ans[maxn],mx[maxn],mn[maxn];
bool occ[maxn];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    rep(i,1<<k) mx[i]=-1e9, mn[i]=1e9, ans[i]=2e9;
    rep(i,n){
        int u;
        cin>>u;
        occ[u]=1, mx[u]=u, mn[u]=u;
    }
    for (int i=0;i<k;++i){
        for (int j=0;j<(1<<k);j+=(1<<i+1)){
            rep(t,1<<i){
                ans[j+t]=ans[j+t+(1<<i)]=min(ans[j+t],ans[j+t+(1<<i)]);
                ans[j+t]=min(ans[j+t],mn[j+t+(1<<i)]-mx[j+t]);
                ans[j+t+(1<<i)]=min(ans[j+t+(1<<i)],mn[j+t]-mx[j+t+(1<<i)]+(1<<i+1));
            }
        }
        for (int j=0;j<(1<<k);j+=(1<<i+1)){
            rep(t,1<<i){
                int upmn0=min(mn[j+t],mn[j+t+(1<<i)]);
                int upmn1=min(mn[j+t+(1<<i)]-(1<<i),mn[j+t]+(1<<i));
                int upmx0=max(mx[j+t],mx[j+t+(1<<i)]);
                int upmx1=max(mx[j+t+(1<<i)]-(1<<i),mx[j+t]+(1<<i));
                mn[j+t]=upmn0, mn[j+t+(1<<i)]=upmn1;
                mx[j+t]=upmx0, mx[j+t+(1<<i)]=upmx1;
            }
        }
    }
    rep(i,1<<k) cout<<ans[i]<<" ";

    return 0;
}