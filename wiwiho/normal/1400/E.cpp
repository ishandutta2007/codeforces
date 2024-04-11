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

int f(int l, int r, vector<int>& a){
    if(l > r) return 0;
    int mn = *min_element(a.begin() + l, a.begin() + r + 1);
    int ans = r - l + 1;
    vector<int> pos;
    for(int i = l; i <= r; i++){
        if(a[i] == mn){
            pos.eb(i);
        }
    }

    for(int i = l; i <= r; i++){
        a[i] -= mn;
    }

    int lst = l;
    int tmp = mn;
    for(int i : pos){
        tmp += f(lst, i - 1, a);
        lst = i + 1;
    }
    tmp += f(lst, r, a);
    ans = min(ans, tmp);

    for(int i = l; i <= r; i++) a[i] += mn;

    return ans;
}

int main(){
    StarBurstStream

    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    cout << f(0, n - 1, a) << "\n";

    return 0;
}