#include <algorithm>
#include <stack>
#include <istream>
#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
#include <ostream>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef long long ll;
typedef std::pair<ll, ll> pll;
using namespace std;
 
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
 
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
int N;

double D(pll x, pll y) {
    return double(sqrt((x.first-y.first)*(x.first-y.first) + (x.second-y.second)*(x.second-y.second)));
}
void solve() {
    vector<pll> A, B;
    cin >> N;
    double ans = 0;
    for(int i = 0; i < 2*N; i++) {
        ll x, y; cin >> x >> y;
        if(x < 0) x = -x;
        if(y < 0) y = -y;

        if(x == 0) A.push_back({x, y});
        else if(y == 0) B.push_back({x, y});
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int l = 0;
    assert(A.size() == B.size() && A.size() == N);
    for(; l < N; l++) {
        ans += D(A[l], B[l]);
    }

    cout << setprecision(15) << ans << "\n";
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int T = 1;
    cin >> T;
    while(T--)
        solve();
}