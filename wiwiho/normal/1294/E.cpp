//#define NDEBUG

#include <bits/stdc++.h>
#include <bits/extc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define eb(a) emplace_back(a)
#define pf(a) push_front(a)
#define pob pop_back()
#define pof pop_front()
#define F first
#define S second
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}
#define pii pair<int, int>
#define pll pair<ll, ll>
#define tiii tuple<int, int, int>
#define mt make_tuple
#define gt(t, i) get<i>(t)
#define iceil(a, b) ((a) / (b) + !!((a) % (b)))

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;
using namespace __gnu_pbds;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

template<typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}

int main(){
    StarBurstStream

    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(m, vector<int>(n));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[j][i];
            if(a[j][i] % m == (j + 1) % m) a[j][i] = (a[j][i] - 1) / m;
            else a[j][i] = -1;
            if(a[j][i] >= n) a[j][i] = -1;
        }
    }

    int ans = 0;
    for(int i = 0; i < m; i++){
        //printv(a[i], cerr);
        vector<int> cnt(n);
        for(int j = 0; j < n; j++){
            if(a[i][j] != -1){
                cnt[(j - a[i][j] + n) % n]++;
            }
        }
        int mn = n;
        for(int j = 0; j < n; j++){
            mn = min(mn, n - cnt[j] + j);
        }
        //printv(cnt, cerr);
        //cerr << "test " << i << " " << mn << "\n";
        ans += mn;
    }
    cout << ans << "\n";

    return 0;
}