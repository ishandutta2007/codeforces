#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=0;

vector<pair<int,int>> ans;
set<int> s;
vector<int> a;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        s.clear(), ans.clear();
        int tmp=n;
        while (true){
            s.insert(tmp);
            if (tmp==2) break;
            for (int i=1;i<=n;++i){
                if (i*i>=tmp){ tmp=i; break; }
            }
        }
        for (int i=3;i<=n;++i){
            if (!s.count(i)) ans.push_back({i,n});
        }
        int p=s.size();
        a.clear(); a.push_back(0);
        for (int x:s) a.push_back(x);
        for (int i=p;i>=2;--i){
            ans.push_back({a[i],a[i-1]});
            ans.push_back({a[i],a[i-1]});
        }
        cout << ans.size() << '\n';
        for (auto x:ans) cout << x.first << " " << x.second << '\n';
    }
}