#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define al(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pc(x) __builtin_popcount(x)
#define pb push_back


vector<int> solve(vector<int> a) {
    int n = a.size();
    vector<int> ret;
    int cnt = 0;
    unordered_map<int, int> mp, vis;
    for(int i = 0; i < n; ++i) cin >> a[i];
    int last = 0;
    for(int i = 0; i < n; ++i) {
        if(a[i] > 0) {
            if(mp[a[i]] || vis[a[i]]) return vector<int>();
            vis[a[i]] = 1;
            mp[a[i]] = 1;
            cnt += 1;
        } else {
            a[i] = -a[i];
            if(!mp[a[i]]) return vector<int>();
            mp[a[i]] = 0;
            cnt -= 1;
        }
        if(cnt == 0) {
            ret.push_back(i - last + 1);
            last = i + 1;
            vis.clear();
        }
    }
    if(cnt) return vector<int>();
    return ret;
}
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> ans = solve(a);
    if(ans.empty()) cout << -1 << endl;
    else {
        cout << ans.size() << endl;
        for(int i : ans) cout << i << " ";
        cout << endl;
    }
}