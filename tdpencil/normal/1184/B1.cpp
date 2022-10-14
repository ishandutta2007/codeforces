#include <algorithm>
#include <stack>
#include <istream>
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
#include <ostream>

typedef long long ll;

using namespace std;
 
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
 
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


const int MAX_VAL=2e9;
void run_case()
{
    int S, B;
    cin >> S >> B;

    vector<int> A(S);
    for(auto& a: A)
        cin >> a;
    vector<pair<int, int>> s(B);
    for(auto &e: s) {
        cin >> e.first >> e.second;
    }

    sort(s.begin(), s.end());
    vector<int64_t> prefixSums(B);
    for(int i = 0; i < B; i++) prefixSums[i] = s[i].second;
    for(int i = 1; i < B; i++) prefixSums[i] += prefixSums[i-1];
    for(int i = 0; i < S; i++) {
        // if we can attack that ship then we can attack all the ships before it
        int p = upper_bound(s.begin(), s.end(), make_pair(A[i], MAX_VAL)) - s.begin();
        p--;
        if(p < 0) {
            cout << 0 << " ";
            continue;
        }
        cout << prefixSums[p] << " ";
    }
    cout << "\n";
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    // TENCIL ORZ?
    int T=1;
    // cin >> T;
    while(T--)
        run_case();
}