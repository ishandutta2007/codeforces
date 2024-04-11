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

using namespace std;
 
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
 
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
template<typename T>
using indexed_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;


void solve() {
    ll N; cin >> N;
    ll ans = -1;
    for(ll i = 2; i * i <= N; i++) {
        if(N%i == 0) {
            ans = i;
            break;
        }
    }
    if(ans == -1) ans = N;
    int c=0;
    if(N&1) {
        c++;
        N -= ans;
    }

    cout << c + N / 2 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int T = 1;
    while(T--)
        solve();
}