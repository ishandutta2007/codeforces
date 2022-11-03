/**
 *    author:  otera    
**/
#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll INF=1LL<<60;
#define rep(i, n) for(int i = 0; i < n; ++ i)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
#define fr first
#define sc second
#define all(c) c.begin(),c.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

void solve() {
    int n; cin >> n;
    if(n == 3) {
        cout << "2\n3 2\n3 2\n";
        return;
    }
    if(n == 4) {
        cout << "3\n3 4\n4 2\n4 2\n";
        return;
    }
    vector<P> ans;
    vector<int> nums(n + 1);
    iota(all(nums), 0);
    int cur = n;
    vector<int> a = {n};
    for(int i = n - 1; i >= 3; -- i) {
        if((i - 1) * 8 < cur) {
            ans.push_back({cur, i});
            nums[cur] = (nums[cur] + nums[i] - 1) / nums[i];
            cur = i;
            a.push_back(cur);
        } else {
            ans.push_back({i, cur});
            nums[i] = (nums[i] + nums[cur] - 1) / nums[cur];
        }
    }
    // ans.push_back({cur, 4}); nums[cur] = (nums[cur] + nums[4] - 1) / nums[4];
    // ans.push_back({3, 4}); nums[3] = (nums[3] + nums[4] - 1) / nums[4];
    // ans.push_back({2, 4}); nums[2] = (nums[2] + nums[4] - 1) / nums[4];
    // rep(i, n + 1) {
    //     cerr << nums[i] << " \n"[i == n];
    // }
    sort(all(a));
    int sz = (int)a.size();
    int po1 = -1;
    int ma1 = -1;
    int po2 = 2;
    rep(i, sz) {
        if(chmax(ma1, nums[a[i]])) po1 = a[i];
    }
    for(int i = sz - 1; i >= 0; -- i) {
        if(a[i] == po1) continue;
        // cerr << a[i] << "\n";
        ans.push_back({a[i], po1});
        nums[a[i]] = (nums[a[i]] + nums[po1] - 1) / nums[po1];
    }
    // ans.push_back({a.back(), 4}); nums[a.back()] = (nums[a.back()] + nums[4] - 1) / nums[4];
    // ans.push_back({4, a.back()}); nums[4] = (nums[4] + nums[a.back()] - 1) / nums[a.back()];
    // ans.push_back({a.back(), 4}); nums[a.back()] = (nums[a.back()] + nums[4] - 1) / nums[4];
    // cerr << po1 << " " << po2 << "\n";
    while(nums[po1] > 1 and nums[po2] > 1) {
        if(nums[po1] > nums[po2]) {
            ans.push_back({po1, po2});
            nums[po1] = (nums[po1] + nums[po2] - 1) / nums[po2];
        } else {
            ans.push_back({po2, po1});
            nums[po2] = (nums[po2] + nums[po1] - 1) / nums[po1];
        }
    }
    assert((int)ans.size() <= n + 5);
    cout << (int)ans.size() << "\n";
    rep(i, (int)ans.size()) {
        cout << ans[i].fr << " " << ans[i].sc << "\n";
    }
    int cnt1 = 0, cnt2 = 0;
    for(int i = 1; i <= n; ++ i) {
        if(nums[i] == 1) ++ cnt1;
        if(nums[i] == 2) ++ cnt2;
    }
    assert(cnt1 == n - 1 and cnt2 == 1);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(20);
	int t; cin >> t; rep(i, t)solve();
	// solve();
    return 0;
}