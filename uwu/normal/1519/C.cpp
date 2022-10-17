#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=2e5+1;

ll u[MAXN], s[MAXN];
vector<ll> a[MAXN];
ll ans[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        for (int i=1;i<=n;++i) a[i].clear(), ans[i]=0;
        for (int i=1;i<=n;++i) cin >> u[i];
        for (int i=1;i<=n;++i){
            cin >> s[i];
            a[u[i]].push_back(s[i]);
        }
        for (int i=1;i<=n;++i){
            int k=a[i].size();
            a[i].push_back(0);
            sort(a[i].begin(),a[i].end());
            ll tot=accumulate(a[i].begin(),a[i].end(),0LL);
            for (int j=1;j<=k;++j) a[i][j]+=a[i][j-1];
            for (int j=1;j<=k;++j){
                ans[j]+=tot-a[i][k%j];
            }
        }
        for (int i=1;i<=n;++i) cout << ans[i] << " ";
        cout << '\n';
    }
}