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
#define iceil(a, b) ((a + b - 1) / b)
#define tomax(a, b) (a = max(a, b))
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

vector<vector<int>> g;
vector<int> pr, dpt;
vector<vector<int>> dv;
vector<int> qd;

void dfs(int now, int p){
    pr[now] = p;
    dv[dpt[now]].eb(now);
    for(int i : g[now]){
        if(i == p) continue;
        dpt[i] = dpt[now] + 1;
        dfs(i, now);
    }
}

bool check(int d, int l){
    cout << "? " << dv[d].size() << " ";
    for(int i : dv[d]) cout << i << " ";
    cout << "\n" << flush;
    int x, tl;
    cin >> x >> tl;
    qd[d] = x;
    return tl == l;
}

int main(){
    StarBurstStream

    int T;
    cin >> T;

    while(T--){

        int n;
        cin >> n;

        g.clear();
        g.resize(n + 1);
        pr.clear();
        pr.resize(n + 1);
        dpt.clear();
        dpt.resize(n + 1);
        dv.clear();
        dv.resize(n + 1);
        qd.clear();
        qd.resize(n + 1);

        for(int i = 0; i < n - 1; i++){
            int u, v;
            cin >> u >> v;
            g[u].eb(v);
            g[v].eb(u);
        }

        cout << "? " << n << " ";
        for(int i = 1; i <= n; i++) cout << i << " ";
        cout << "\n" << flush;

        int rt, d;
        cin >> rt >> d;
        dfs(rt, rt);

        int l = 0, r = n;
        while(l < r){
            int m = (l + r + 1) / 2;
            if(dv[m].empty() || !check(m, d)) r = m - 1;
            else l = m;
        }

        int n1 = qd[l];
        d -= dpt[n1];

        if(d != 0){
            int tmp = n1;
            while(dpt[tmp] != d) tmp = pr[tmp];

            cout << "? " << dv[d].size() - 1 << " ";
            for(int i : dv[d]){
                if(i != tmp) cout << i << " ";
            }
            cout << "\n" << flush;

            int n2, aaa;
            cin >> n2 >> aaa;

            cout << "! " << n1 << " " << n2 << "\n" << flush;
        }
        else{
            cout << "! " << n1 << " " << rt << "\n" << flush;
        }

        string s;
        cin >> s;

        if(s == "Incorrect") return 0;

    }

    return 0;
}