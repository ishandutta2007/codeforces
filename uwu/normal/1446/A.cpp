#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=2e5+1;

ll arr[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        ll n, w; cin >> n >> w;
        ll wf = (w+1)/2;
        int idx=-1;
        for (int i=1,a;i<=n;++i){
            cin >> arr[i];
            if (arr[i]>=wf&&arr[i]<=w) idx=i;
        }
        if (idx!=-1) cout << 1 << '\n' << idx << '\n';
        else{
            vector<int> ans;
            ll tot=0;
            for (int i=1;i<=n;++i){
                if (arr[i]<=w) tot+=arr[i], ans.push_back(i);
                if (tot>=wf&&tot<=w) break;
            }
            if (tot>=wf&&tot<=w){
                cout << ans.size() << '\n';
                for (int x:ans) cout << x << " " ;
                cout << '\n';
            }
            else cout << -1 << '\n';
        }
    }
}