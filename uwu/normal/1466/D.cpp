#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e5+1;

ll a[MAXN], deg[MAXN], ans[MAXN];
priority_queue<int,vector<int>,greater<int>> pq;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        for (int i=1;i<=n;++i) cin >> a[i], deg[i]=0;
        for (int i=1;i<=n-1;++i){
            int a, b; cin >> a >> b;
            deg[a]++, deg[b]++;
        }
        ll tot=0;
        for (int i=1;i<=n;++i){
            tot+=deg[i]*a[i];
            for (int j=2;j<=deg[i];++j) pq.push(a[i]);
        }
        ans[n-1]=tot;
        for (int i=n-2;i>=1;--i){
            tot=tot-pq.top(); pq.pop();
            ans[i]=tot;
        }
        for (int i=1;i<=n-1;++i) cout << ans[i] << " ";
        cout << '\n';

    }
}