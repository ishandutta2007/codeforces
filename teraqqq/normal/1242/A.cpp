#include <iostream>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <iomanip>
#include <numeric>
#include <cmath>

#define F first
#define S second
#define pb push_back
#define rsz resize
 
using namespace std;
using ll = long long;
using ld = double;
using ull = unsigned long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vpi = vector<pi>;
using vl = vector<ll>;
using vul = vector<ull>;

template<class T> void ckmin(T &a, T b) { a = min(a, b); }
template<class T> void ckmax(T &a, T b) { a = max(a, b); }

const int INF = 1e9;
const ll LINF = 1e18;
const ld PI = atan((ld)1);

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin >> n; map<ll, int> f;
    for(ll i = 2; i*i <= n; ++i) 
        for(; n%i == 0; n /= i) f[i]++;
    if(n > 1) f[n]++;
    if(f.size() == 1)
        for(auto x : f) cout << x.F << endl;
    else cout << 1 << endl;
}