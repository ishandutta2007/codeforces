
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
#define ef(a) emplace_front(a)
#define pob pop_back()
#define pof pop_front()
#define mp(a, b) make_pair(a, b)
#define F first
#define S second
#define mt make_tuple
#define gt(t, i) get<i>(t)
#define tomax(a, b) ((a) = max((a), (b)))
#define tomin(a, b) ((a) = min((a), (b)))
#define topos(a) ((a) = (((a) % MOD + MOD) % MOD))
#define uni(a) a.resize(unique(iter(a)) - a.begin())
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}

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

ll ifloor(ll a, ll b){
    if(b < 0) a *= -1, b *= -1;
    if(a < 0) return (a - b + 1) / b;
    else return a / b;
}

ll iceil(ll a, ll b){
    if(b < 0) a *= -1, b *= -1;
    if(a > 0) return (a + b - 1) / b;
    else return a / b;
}

vector<int> prime, lpf, id;
vector<int> dsu, sz;

int findDSU(int a){
    if(dsu[a] != a) dsu[a] = findDSU(dsu[a]);
    return dsu[a];
}

void unionDSU(int a, int b){
    a = findDSU(a); b = findDSU(b);
    if(a == b) return;
    if(sz[a] < sz[b]) swap(a, b);
    dsu[b] = a;
    sz[a] += sz[b];
}

void sieve(int n){
    lpf.resize(n + 1, 1);
    id.resize(n + 1, -1);
    for(int i = 2; i <= n; i++){
        if(lpf[i] == 1){
            lpf[i] = i;
            id[i] = prime.size();
            prime.eb(i);
        }
        for(int j : prime){
            if((ll)i * j > n) break;
            lpf[i * j] = j;
            if(j == lpf[i]) break;
        }
    }
}

int main(){
    StarBurstStream

    sieve(1000001);
    dsu.resize(prime.size());
    sz.resize(prime.size(), 1);
    for(int i = 0; i < prime.size(); i++) dsu[i] = i;

    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    set<pii> one;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        int tmp = a[i];
        int lst = -1;

        while(tmp > 1){
            int now = lpf[tmp];
            while(tmp % now == 0){
                tmp /= now;
            }
            if(lst != -1) unionDSU(id[lst], id[now]);
            lst = now;
        }
    }
    for(int i = 1; i <= n; i++){
        int p = findDSU(id[lpf[a[i]]]);

        vector<int> f;
        int tmp = a[i] + 1;
        while(tmp > 1){
            int now = lpf[tmp];
            while(tmp % now == 0){
                tmp /= now;
            }
            f.eb(now);
        }
        for(int f1 : f){
            int p1 = findDSU(id[f1]);
            for(int f2 : f){
                int p2 = findDSU(id[f2]);
                if(p1 != p2) one.insert(mp(p1, p2));
            }
            one.insert(mp(p1, p));
            one.insert(mp(p, p1));
        }
    }
//    printv(one, cerr);

    while(q--){
        int s, t;
        cin >> s >> t;
        s = a[s];
        t = a[t];
        int ps = findDSU(id[lpf[s]]);
        int pt = findDSU(id[lpf[t]]);

        if(ps == pt){
            cout << "0\n";
            goto ok;
        }

        if(one.find(mp(ps, pt)) != one.end()){
            cout << "1\n";
            goto ok;
        }

        cout << "2\n";

        ok:;
    }

    return 0;
}