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

int main() {
    ll n, k, s;
    cin >> n >> k >> s;
    if(s < k || s > (n - 1) * k) {
        cout << "NO" << endl;
        return 0;
    }
    int cur = 1;
    ll tot = 0;
    vector<int> ans;
    auto big_move = [&]() {
        if(cur == 1) {
            cur = n;
        } else if(cur == n) {
            cur = 1;
        } else {
            assert(0);
        }
        ans.push_back(cur);
        tot += n - 1;
    };
    auto small_move = [&]() {
        if(cur == 1) {
            cur = 2;
        } else {
            cur = cur - 1;
        }
        ans.push_back(cur);
        tot += 1;
        assert(1 <= cur && cur <= n);
    };
    auto mid_move = [&](int k) {
        if(cur == 1) {
            cur += k;
        } else if(cur == n) {
            cur -= k;
        } else {
            assert(0);
        }
        assert(1 <= cur && cur <= n);
        ans.push_back(cur);
        tot += k;
    };
    // (n-1) * x + y = s
    //         x + y = k

    //        (n-2)x = s-k
    //        let x = (s-k) / (n-2)
    //        s -= (n-1)*x, k -= x
    //        assert(s >= k && s - k <= n - 1)
    //        if(s > k) mid_move(s - k + 1)
    //        s -= s - k + 1, k -= 1
    if(n == 2) {
        assert(s == k);
        for(int i=1;i<=k;++i) small_move();
        cout << "YES\n";
        for(int i : ans) cout << i << " "; cout << endl;
        return 0;
    }
    ll x = (s - k) / (n - 2);
    for(int i=1;i<=x;++i) big_move();
    s -= (n-1)*x, k -= x;
    assert(s >= k && s - k <= n - 1);
    if(s > k) {
        mid_move(s - k + 1);
        s -= s - k + 1, k -= 1;
    }
    assert(s == k);
    for(int i=1;i<=k;++i) small_move();
    s -= k, k -= k;
    assert(s == 0 && k == 0);
    cout << "YES\n";
    for(int i : ans) cout << i << " "; cout << endl;
}