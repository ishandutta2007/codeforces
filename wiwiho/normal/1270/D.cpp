//#define NDEBUG

#include <bits/stdc++.h>

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
#define B back()
#define FR front()
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

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

int main(){
    StarBurstStream

    int n, k;
    cin >> n >> k;

    if(k == 1){
        cout << "! 1\n" << flush;
        return 0;
    }

    vector<int> a(n + 1, -1);
    vector<pii> b;
    vector<int> g;
    for(int i = 0; i < 2; i++){
        g.clear();
        for(int j = 1; j <= n && g.size() < k; j++){
            if(a[j] == -1) g.eb(j);
        }

        cout << "? ";
        printv(g, cout);
        cout << flush;

        int p, v;
        cin >> p >> v;
        a[p] = v;
        b.eb(mp(v, p));
    }

    pii t = b.back();
    pii s = b[b.size() - 2];

    int m = 1;
    for(int i = 0; i < g.size(); i++){
        if(g[i] == t.S) continue;
        cout << "? ";
        for(int j = 0; j < g.size(); j++){
            if(j != i) cout << g[j] << " ";
        }
        cout << s.S << "\n" << flush;
        int p, v;
        cin >> p >> v;
        if(p == t.S){
            if(s.F < t.F) m++;
        }
        else{
            if(s.F > t.F) m++;
        }
    }

    //printv(a, cerr);

    cout << "! " <<  m << "\n" << flush;

    return 0;
}