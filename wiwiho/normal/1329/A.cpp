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

    int n, m;
    cin >> n >> m;

    vector<int> l(m);
    for(int i = 0; i < m; i++) cin >> l[i];

    vector<int> p(m);
    for(int i = 0; i < m; i++){
        p[i] = i + 1;
        if(i + 1 > n - l[i] + 1){
            cout << "-1\n";
            return 0;
        }
    }

    int lst = n + 1;
    for(int i = m - 1; i >= 0; i--){
        if(p[i] + l[i] >= lst){
            break;
        }
        p[i] = lst - l[i];
        lst = p[i];
    }

    if(p[0] != 1) cout << "-1\n";
    else printv(p, cout);

    return 0;
}