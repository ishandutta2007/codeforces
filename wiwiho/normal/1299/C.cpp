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

vector<int> dsu, rk, mx;
vector<ll> sum;

void initDSU(int n){
    dsu.resize(n);
    rk.resize(n);
    sum.resize(n);
    mx.resize(n);
    for(int i = 0; i < n; i++) dsu[i] = i, rk[i] = 1, mx[i] = i;
}

int findDSU(int x){
    if(dsu[x] == x) return x;
    dsu[x] = findDSU(dsu[x]);
    return dsu[x];
}

void unionDSU(int a, int b){
    int pa = findDSU(a), pb = findDSU(b);
    if(pa == pb) return;
    if(rk[pa] > rk[pb]) swap(pa, pb);
    if(rk[pa] == rk[pb]) rk[pb]++;
    sum[pb] += sum[pa];
    mx[pb] = max(mx[pb], mx[pa]);
    dsu[pa] = pb;
}

#define ld long double

int main(){
    StarBurstStream

    int n;
    cin >> n;

    vector<ll> a(n);
    initDSU(n);
    for(int i = 0; i < n; i++) cin >> a[i], sum[i] = a[i];

    for(int i = n - 2; i >= 0; i--){
        ll now = a[i];
        int r = i + 1;
        while(r < n){
            int p = findDSU(r);
            if((sum[p] + now) / (ld)(mx[p] - i + 1) > now / (ld)(r - i)) break;
            //cerr << i << " " << r << ' ' << p << " " << sum[p] << " " << now <<" " << mx[p] << "\n";
            now += sum[p];
            unionDSU(i, r);
            r = mx[p] + 1;
        }
    }

    vector<ld> ans(n);
    for(int i = 0; i < n; i++){
        int p = findDSU(i);
        int r = mx[p];
        ld an = sum[p] / (ld)(r - i + 1);
        for(int j = i; j <= r; j++) ans[j] = an;
        i = r;
    }
    for(int i = 0; i < n ;i++) cout << fixed << setprecision(20) << ans[i] << "\n";

    //printv(dsu, cerr);
    //printv(sum, cerr);
    //printv(mx, cerr);

    return 0;
}