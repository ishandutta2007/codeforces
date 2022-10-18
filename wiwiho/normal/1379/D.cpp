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

    int n, h, m, k;
    cin >> n >> h >> m >> k;

    map<int, vector<pii>> e;

    for(int i = 0; i < n; i++){
        int hr, mn;
        cin >> hr >> mn;
        if(mn >= m / 2) mn -= m / 2;

        int l = max(0, mn - k + 1);
        if(l < mn){
            e[l].eb(mp(1, i + 1));
            e[mn].eb(mp(-1, i + 1));
        }

        if(mn - k + 1 < 0){
            e[m / 2 + mn - k + 1].eb(mp(1, i + 1));
        }
    }

    if(e.empty()){
        cout << "0 0\n";
        return 0;
    }

    set<int> now;
    int ans = MAX, t = -1;
    for(auto& i : e){
//        cerr << i.F << "  ";
//        printv(i.S, cerr);
        for(auto j : i.S){
            if(j.F == 1) now.insert(j.S);
            else now.erase(j.S);
        }
        if(now.size() < ans){
            ans = now.size();
            t = i.F;
        }
    }

    now.clear();
    for(auto& i : e){
        for(auto j : i.S){
            if(j.F == 1) now.insert(j.S);
            else now.erase(j.S);
        }
        if(now.size() < ans){
            ans = now.size();
            t = i.F;
        }
        if(i.F == t) break;
    }

    cout << ans << " " << (t + k) % (m / 2) << "\n";
    printv(now, cout);

    return 0;
}