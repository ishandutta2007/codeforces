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

set<int> s;

vector<vector<int>> g;
vector<int> sz, mx;

void getsz(int now, int p){
    sz[now] = 1;
    mx[now] = 0;
    for(int i : g[now]){
        if(i == p || s.find(i) == s.end()) continue;
        getsz(i, now);
        mx[now] = max(mx[now], sz[i]);
        sz[now] += sz[i];
    }
    mx[now] = max(mx[now], (int)s.size() - sz[now]);
}

void rm(int now, int t){
    if(now == t || s.find(now) == s.end()) return;
    s.erase(now);
    for(int i : g[now]){
        if(i == t || s.find(i) == s.end()) continue;
        rm(i, t);
    }
}

int main(){
    StarBurstStream

    int n;
    cin >> n;

    g.resize(n + 1);
    sz.resize(n + 1);
    mx.resize(n + 1);

    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        g[u].eb(v);
        g[v].eb(u);
    }

    for(int i = 1; i <= n; i++) s.insert(i);

    while(s.size() > 1){
        getsz(*s.begin(), *s.begin());
        int t = -1;
        for(int i : s){
            if(mx[i] <= s.size() / 2){
                t = i;
                break;
            }
        }

//        printv(sz, cerr);
//        printv(mx, cerr);
//        printv(s, cerr);

        vector<int> c;
        for(int i : g[t]){
//            cerr << i << " " << (s.find(i) != s.end()) << "\n";
            if(s.find(i) != s.end()) c.eb(i);
        }

        if(c.size() == 1){
            cout << "? " << t << " " << c[0] << "\n" << flush;
            int ans;
            cin >> ans;
            if(ans == t) s.erase(c[0]);
            else s.erase(t);
            continue;
        }

        cout << "? " << c[0] << " " << c[1] << "\n" << flush;
        int ans;
        cin >> ans;

        if(ans == t){
            rm(c[0], t);
            rm(c[1], t);
        }
        else if(ans == c[0]) rm(t, c[0]);
        else rm(t, c[1]);
    }

    cout << "! " << *s.begin() << "\n";

    return 0;
}