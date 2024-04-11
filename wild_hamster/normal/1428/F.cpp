#include <utility>
#include <iostream>
#include <cmath>
#include <deque>
#include <string>
#include <time.h>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <bitset>
#include <fstream>

#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
#define N 13
#define OFF 400001
#define MOD 1000000007
#define NN 1000000
ll n, m, k, w, r;
ll c[1005000], b[1005000], a[1005005], dp[1005000], maxdp[1005000];
ll t, x, y, z;
ll Abs(ll x) {
    return x > 0 ? x : -x;
}
vector<pii> ans;
vector<pair<ll, pii> > st;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    string s;
    cin >> s;
    ll ans = 0;
    st.push_back(mp(n + 5, mp(0, 0)));
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        ll x = s[i] - '0';
        if (x == 0) {
            sum = 0;
            ans += st.back().Y.Y;
        } else {
            sum++;
            ll last_sum = st.back().Y.Y;
            ll cur_sum = last_sum + (i + 1 - st.back().Y.X) * sum - sum + 1;
            //cout << cur_sum << "\n";
            while (sum > st.back().X) {
                ll cur_zalupa = st.back().X;
                ll cur_pos = st.back().Y.X;
                //cout << "POP " << cur_zalupa << " " << cur_pos << "\n";
                st.pop_back();
                cur_sum += (cur_pos - st.back().Y.X) * (sum - cur_zalupa);
            }
            //cout << "PUSH " << sum << " " << i+1 << " " << cur_sum << "\n";
            if (st.size() > 1) {
                cur_sum += sum - 1;
            }
            st.push_back(mp(sum, mp(i + 1, cur_sum)));
            ans += cur_sum;
        }
        //cout << " ANS " << ans << "\n";
    }
    cout << ans << "\n";
    return 0;
}