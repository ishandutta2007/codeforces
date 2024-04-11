//#define NDEBUG

#include <bits/stdc++.h>
#include <bits/extc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define pb(a) push_back(a)
#define eb(a) emplace_back(a)
#define pf(a) push_front(a)
#define pob pop_back()
#define pof pop_front()
#define mp(a, b) make_pair(a, b)
#define F first
#define S second
#define mt make_tuple
#define gt(t, i) get<i>(t)
#define iceil(a, b) (((a) + (b) - 1) / (b))
#define tomax(a, b) ((a) = max((a), (b)))
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}

//#define TEST

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<ld, ld>;
using tiii = tuple<int, int, int>;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

template<typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}

int main(){
    StarBurstStream

    int n;
    cin >> n;

    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<vector<ll>> ans(3);

    if(n <= 3){
        for(int i = 0; i < n; i++){
            cout << i + 1 << " " << i + 1 << "\n";
            cout << -a[i] << "\n";
        }
        for(int i = n; i < 3; i++){
            cout << "1 1\n0\n";
        }
        return 0;
    }


    pll t = mp(1, 1);
//    cerr << t << "\n";

    for(int i = 0; i < n - 1; i++){
        ans[0].eb(-t.F * n * a[i]);
        ans[1].eb(t.S * (n - 1) * a[i]);
    }
    ans[0].eb(0);

    ans[2].eb(-a.back());

    cout << 1 << " " << n << "\n";
    printv(ans[0], cout);
    cout << 1 << " " << n - 1 << "\n";
    printv(ans[1], cout);
    cout << n << " " << n << "\n";
    printv(ans[2], cout);

    return 0;
}