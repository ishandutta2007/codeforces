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

vector<vector<int>> g, r;
vector<bool> d, vst;

vector<int> ans;

bool tmp = true;

void dfs2(int now){
//    cerr << "test " << tmp << " " << now <<"\n";
    d[now] = true;
    for(int i : r[now]){
        if(!d[i]) dfs2(i);
    }
}

int n;

void dfs1(int now){
    vst[now] = true;
    for(int i : g[now]){
        if(!vst[i]) dfs1(i);
    }
    if(d[now]) return;
    ans[now % n] = (now >= n);
    dfs2((now + n) % (2 * n));
    if(d[now]){
        cout << "NO\n";
        exit(0);
    }
}

int main(){
    StarBurstStream

    int a, b;
    cin >> n >> a >> b;

    g.resize(2 * n);
    r.resize(2 * n);
    d.resize( 2 * n);
    vst.resize(2 * n);
    ans.resize(n, -1);

    map<int, int> p;
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        p[t] = i;
    }

    for(pii i : p){
        if(p.find(a - i.F) != p.end()) g[i.S].eb(p[a - i.F]), g[i.S + n].eb(p[a - i.F] + n);
        if(p.find(b - i.F) != p.end()) g[i.S + n].eb(p[b - i.F] + n), g[i.S].eb(p[b - i.F]);
    }

    for(int i = 0; i < 2 * n; i++){
        for(int j : g[i]){
            r[j].eb(i);
        }
    }

    for(pii i : p){
        if(p.find(a - i.F) == p.end()) dfs2(i.S);
        if(p.find(b - i.F) == p.end()) dfs2(i.S + n);
    }
    tmp = false;

    for(int i = 0; i < 2 * n; i++){
        if(!vst[i]) dfs1(i);
    }

//    printv(ans, cerr);

    for(int i = 0; i < n; i++){
        if(ans[i] == -1){
//            cerr << "t " << i << "\n";
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    printv(ans, cout);

    return 0;
}