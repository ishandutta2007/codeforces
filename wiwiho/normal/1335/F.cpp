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

vector<vector<int>> r;
vector<int> g, c;
vector<bool> isc;
int n, m;
vector<int> tmp;

int trans(int x, int y){
    return x * m + y;
}

void dfs(int now, int p, int d, int t, int sz){
    if(c[now] == 0) tmp[(d - t + sz) % sz] = 1;
    for(int i : r[now]){
        if(isc[i] || i == p) continue;
        dfs(i, now, d + 1, t, sz);
    }
}

int main(){
    StarBurstStream

    int T;
    cin >> T;

    while(T--){

        cin >> n >> m;
        vector<string> a(n), cs(n);
        for(int i = 0; i < n; i++) cin >> cs[i];
        for(int i = 0; i < n; i++) cin >> a[i];

        c.clear();
        c.resize(n * m);
        r.clear();
        r.resize(n * m);
        g.clear();
        g.resize(n * m);
        isc.clear();
        isc.resize(n * m);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(a[i][j] == 'L') g[trans(i, j)] = (trans(i, j - 1));
                else if(a[i][j] == 'R') g[trans(i, j)] = (trans(i, j + 1));
                else if(a[i][j] == 'U') g[trans(i, j)] = (trans(i - 1, j));
                else g[trans(i, j)] = (trans(i + 1, j));

                c[trans(i, j)] = cs[i][j] - '0';
            }
        }

        for(int i = 0; i < n * m; i++){
            r[g[i]].eb(i);
        }

        vector<int> st;
        vector<int> vst(n * m, -1);
        for(int i = 0; i < n * m; i++){
            if(vst[i] != -1) continue;
            int v = i;
            while(vst[v] == -1){
                vst[v] = i;
                v = g[v];
            }
            if(vst[v] == i) st.eb(v);
        }
//        printv(vst, cerr);

//        printv(st, cerr);

        int aa = 0, ab = 0;
        for(int i : st){
            tmp.clear();
            vector<int> cy;
            while(!isc[i]){
                isc[i] = true;
                cy.eb(i);
                i = g[i];
            }
            tmp.resize(cy.size());
            for(int j = 0; j < cy.size(); j++){
                dfs(cy[j], cy[j], 0, j, cy.size());
            }
            aa += cy.size();
            for(int j : tmp) ab += j;
        }

        cout << aa << " " << ab << "\n";
    }

    return 0;
}