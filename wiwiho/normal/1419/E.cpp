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

    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        int tn = n;

        vector<int> d, p;

        for(int i = 1; i * i <= n; i++){
            if(n % i) continue;
            if(i > 1) d.eb(i);
            if(i != n / i) d.eb(n / i);
        }

        for(int i = 2; i * i <= n; i++){
            if(n % i) continue;
            p.eb(i);
            while(n % i == 0) n /= i;
        }
        if(n > 1) p.eb(n);

//        printv(p, cerr);
//        printv(d, cerr);

        if(p.size() == 1){
            printv(d, cout);
            cout << "0\n";
            continue;
        }
        if(d.size() == 3){
            printv(d, cout);
            cout << "1\n";
            continue;
        }

        set<int> use;
        vector<int> c(p.size());
        for(int i = 0; i < p.size(); i++){
            c[i] = p[i] * p[(i + 1) % p.size()];
            if(use.find(c[i]) != use.end()){
                if(tn % (c[i] * p[i]) == 0) c[i] *= p[i];
                else c[i] *= p[(i + 1) % p.size()];
            }
            use.insert(c[i]);
        }

        vector<vector<int>> t(p.size());
        for(int i : d){
            if(use.find(i) != use.end()) continue;
            for(int j = 0; j < p.size(); j++){
                if(i % p[j]) continue;
                t[j].eb(i);
                break;
            }
        }

//        for(int i = 0; i < p.size(); i++){
//            cerr << p[i] << " " << c[i] << "  ";
//            printv(t[i], cerr);
//        }

        for(int i = 0; i < p.size(); i++){
            for(int j : t[i]) cout << j << " ";
            cout << c[i] << " ";
        }
        cout << "\n";
        cout << "0\n";

    }

    return 0;
}