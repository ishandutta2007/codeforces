#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;
typedef long long ll; 
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
 
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


void solve() {
    int N; cin >> N;
    vector<int64_t> A(N); for(auto &a: A) cin >> a;


    int ans = 0;

    for(int i = 0; i < N - 1; i++) {
        int64_t x = A[i];
        int64_t y = A[i+1];

        int64_t c1 = max(x, y);
        int64_t c2 = min(x, y);

        int cur = 0;
        while(c2 < c1) {
            cur ++ ;
            c2 *= 2;
        }

        ans += max(0, cur - 1);
    }

    cout << ans << "\n";
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    
    while(T--)
        solve();
}