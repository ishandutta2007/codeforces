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
    ll t;
    cin >> n >> t;

    vector<ll> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    vector<int> x(n + 1);
    for(int i = 1; i <= n; i++) cin >> x[i];
    if(x[n] != n){
        cout << "No\n";
        return 0;
    }
    for(int i = 1; i <= n - 1; i++){
        if(x[i] > x[i + 1]){
            cout << "No\n";
            return 0;
        }
    }

    ll mx = 3e18;
    vector<ll> b(n + 1);
    for(int i = n; i > 0; i--){
        ll tmx = mx;
        int cnt = 1;
        while(i > 0 && x[i - 1] == x[i]){
            cnt++;
            tmx = min(tmx, a[i] + t - 1);
            i--;
        }
        tmx = min(tmx, a[i] + t - 1);

        if(cnt != x[i] - x[i - 1]){
            cout << "No\n";
            return 0;
        }
        for(int j = x[i]; j > x[i - 1]; j--){
            ll mn = j == x[i] ? 1 : a[j + 1] + t;
            if(mn > mx){
                cout << "No\n";
                return 0;
            }
            b[j] = mx--;
        }
        mx = min(mx, tmx);
    }

    cout << "Yes\n";
    for(int i = 1; i <= n; i++) cout << b[i] << " ";
    cout << "\n";

    return 0;
}