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

    int n, m, k;
    cin >> n >> m >> k;

    if(4 * n * m - 2 * n - 2 * m < k){
        cout << "NO\n";
        return 0;
    }

    vector<pair<int, string>> ans;
    for(int i = 1; i < n && k > 0; i++){
        int t = min(k, m - 1);
        if(t > 0) ans.eb(mp(t, "R"));
        k -= t;
        if(k == 0) break;
        t = min(k, m - 1);
        if(t > 0) ans.eb(mp(t, "L"));
        k -= t;
        if(k == 0) break;
        ans.eb(mp(1, "D"));
        k--;
    }

    if(k > 0){
        int t = min(k, m - 1);
        if(t > 0) ans.eb(mp(t, "R"));
        k -= t;
    }

    for(int i = m; i > 0 && k > 0; i--){
        int t = min(k, n - 1);
        if(t > 0) ans.eb(mp(t, "U"));
        k -= t;
        if(k == 0) break;
        t = min(k, n - 1);
        if(t > 0) ans.eb(mp(t, "D"));
        k -= t;
        if(k == 0) break;
        ans.eb(mp(1, "L"));
        k--;
    }

    if(k > 0){
        int t = min(k, n - 1);
        if(t > 0) ans.eb(mp(t, "U"));
    }

    cout << "YES\n";
    cout << ans.size() << "\n";
    for(auto i : ans){
        cout << i.F << " " << i.S << "\n";
    }

    return 0;
}