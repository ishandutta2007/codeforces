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
#define ar array

void solve() {
    int N; cin >> N;
    int N1, N2;
    cin >> N1 >> N2;
    vector<int> A(N);
    for(auto &a: A)
        cin >> a;

    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());
    int res = N1 + N2;
    while(res < N) {
        A.pop_back();
        res++;
    } 
    double ans = 0;
    double cur = 0;
    if(N1 > N2) swap(N1, N2);
    for(int i = 0; i < N1; i++) {
        cur += A[i];
    }
    cur /= (double) N1;
    for(int i = N1; i < N1+N2; i++) {
        ans += A[i];
    }
    ans /= (double) N2;

    cout << setprecision(15) << ans + cur << "\n";

}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T = 1; //cin >> T;
   
    while(T--)
        solve();
}