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

vector<int> BIT;

int lowbit(int x){
    return x & -x;
}

void modify(int x){
    if(x == 0) return;
    for(; x < BIT.size(); x += lowbit(x)) BIT[x] += 1;
}

int get(int x){
    int ans = 0;
    for(; x > 0; x -= lowbit(x)) ans += BIT[x];
    return ans;
}

int main(){
    StarBurstStream

    int n;
    cin >> n;

    vector<int> a(n), b(n), t(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    vector<int> tmp;
    for(int i = 0; i < n; i++) t[i] = b[i] - a[i], tmp.eb(t[i]);
    lsort(tmp);
    tmp.resize(unique(iter(tmp)) - tmp.begin());

    int m = tmp.size();
    BIT.resize(m + 1);

//    printv(tmp, cerr);

    ll ans = 0;
//    vector<int> testv(m + 1);
    for(int i = n - 1; i >= 0; i--){
        int k = a[i] - b[i];
        k = lower_bound(iter(tmp), k) - tmp.begin();
//        cerr << a[i] - b[i] << " " << k << "\n";

        ans += get(k);
        modify(upper_bound(iter(tmp), t[i]) - tmp.begin());
//        testv[upper_bound(iter(tmp), t[i]) - tmp.begin()]++;
//        printv(testv, cerr);
    }

    cout << ans << "\n";

    return 0;
}