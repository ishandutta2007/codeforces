#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int MAXN = 2e5, M = 1e9+7;
// #define runcase LOL
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ull> vul;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef vector<array<int, 2>> var2;
typedef vector<array<int, 3>> var3;
typedef pair<ll, ll> pl;
typedef vector<pl> vpl;

#define FOR(j, V) for(int j = 0; j < V; j++)
#define DOR(tt, X) for(int tt = X; tt >= 0; --tt)
#define pb push_back
#define all(X) X.begin(),X.end()

// template insertion spaces

struct cmp {
    #define fi first
    #define sc second
    bool operator()(const pl &x, const pl &y) {
        return abs(x.fi)*x.sc < abs(y.fi)*y.sc;
    }
    #undef fi
    #undef sc
};
void solve(int test_case = 0)
{
    int n; cin >> n;
    vi a(n);
    FOR(i, n) cin >> a[i];
    ll s = accumulate(a.begin(), a.end(), 0LL);
    s /= n;
    vi diff(n);
    FOR(i, n) diff[i] = a[i] - s;
    assert(accumulate(all(diff), 0LL) == 0LL);
    ll ans = 0;
    stack<pl> pq1, pq2;
    FOR(i, n) {
        if(diff[i] > 0) {
            while(!pq1.empty() && diff[i] > 0) {
                pl x = pq1.top();
                pq1.pop();
                ans += min(diff[i], -(int)x.first) * (i - x.second);
                if(-x.first > diff[i]) {
                    x.first += diff[i];
                    diff[i] = 0;
                    pq1.push(x);
                } else {
                    diff[i] += x.first;
                }
            }
            if(diff[i])
                pq2.push({diff[i], i});
        } else if(diff[i] < 0) {
            while(!pq2.empty() && diff[i] < 0) {
                pl x = pq2.top();
                pq2.pop();
                ans += min(-diff[i], (int)x.first) * (i - x.second);
                if(x.first + diff[i] > 0) {
                    x.first += diff[i];
                    diff[i] = 0;
                    pq2.push(x);
                } else {
                    diff[i] += x.first;
                }
            }
            if(diff[i])
                pq1.push({diff[i], i});
        }


    }

    cout << ans << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T = 1;
#ifdef runcase
    cin >> T;
#endif

    for(int nt = 0, i; nt < T; nt++) {
        solve(nt);
        ++i;
    }
}