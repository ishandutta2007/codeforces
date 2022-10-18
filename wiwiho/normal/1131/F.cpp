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

vector<int> l, r;
vector<int> dsu, dsul, dsur;

int findDSU(int a){
    if(dsu[a] == a) return a;
    dsu[a] = findDSU(dsu[a]);
    return dsu[a];
}

void unionDSU(int a, int b){
    a = findDSU(a), b = findDSU(b);
    l[dsul[b]] = dsur[a];
    r[dsur[a]] = dsul[b];
    dsur[a] = dsur[b];
    dsu[b] = a;
}

int main(){
    StarBurstStream

    int n;
    cin >> n;

    dsu.resize(n + 1);
    dsul.resize(n + 1);
    dsur.resize(n + 1);
    l.resize(n + 1, -1);
    r.resize(n + 1, -1);
    for(int i = 1; i <= n; i++){
        dsu[i] = dsul[i] = dsur[i] = i;
    }

    for(int i = 0; i < n - 1; i++){
        int x, y;
        cin >> x >> y;
        unionDSU(x, y);
    }

    int now = dsul[findDSU(1)];
    for(int i = 0; i < n; now = r[now], i++){
        cout << now << " ";
    }
    cout << "\n";

    return 0;
}