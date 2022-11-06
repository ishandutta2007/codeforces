#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define DEBUG 0
#define dout if(DEBUG) cout


const int MAXN = 500 + 10;
const int MAXE = 1e5;
const int INF = 1e9;

int z[MAXN];

void z_function(string s) {
    int n = (int) s.length();

    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i <= r) {
            z[i] = min(r - i + 1, z[i - l]);
        }
        else {
            z[i] = 0;
        }

        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }

        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
}

string t[MAXN];
int p[MAXN];
int has[MAXN][MAXN]; // pos, word


struct edge{
    int v, to, cn, cs, f, p;
    edge(int v, int to, int cn, int cs, int f, int p):
        v(v), to(to), cn(cn), cs(cs), f(f), p(p){};
    edge(){};
};


vi g[MAXN];
edge ee[MAXE];
int cnt;
int d[MAXN];
int phi[MAXE];
int prv[MAXN];

void add_edge(int v, int to, int cn, int cs){
    ee[cnt] = edge(v, to, cn, cs, 0, cnt + 1);
    g[v].pb(cnt++);
    ee[cnt] = edge(to, v, 0, -cs, 0, cnt - 1);
    g[to].pb(cnt++);
}

void max_flow(int sr, int sk, int n){
    int v, num, to, cs, cn;
    for(int i = 0; i < n; i++){
        d[i] = INF;
    }
    d[sr] = 0;
    bool was;
    for(int i = 0; i < n; i++){
        was = 0;
        for(int j = 0; j < cnt; j++){
            v = ee[j].v, to = ee[j].to;
            cn = ee[j].cn, cs = ee[j].cs;
            if(d[v] < INF){
                if(cn - ee[j].f > 0){
                    if(d[to] > d[v] + cs){
                        was = 1;
                        d[to] = d[v] + cs;
                    }
                }
            }
        }
        if(!was) break;
    }
    for(int i = 0; i < n; i++){
        phi[i] = d[i];
        dout << "PHI " << i << " " << phi[i] << endl;
    }
    prv[sr] = -1;
    for(;;){
        for(int i = 0; i < n; i++) d[i] = INF;
        d[sr] = 0;
        set<pii > st;
        st.insert(mp(0, sr));
        while(!st.empty()){
            v = st.begin()->second;
            st.erase(st.begin());
            for(int i = 0; i < (int)g[v].size(); i++){
                num = g[v][i];
                to = ee[num].to;
                cs = ee[num].cs + phi[v] - phi[to];
                cn = ee[num].cn;
                if(cn > ee[num].f && d[to] > d[v] + cs){
                    st.erase(mp(d[to], to));
                    d[to] = d[v] + cs;
                    prv[to] = num;
                    st.insert(mp(d[to], to));
                }
            }
        }

        if(d[sk] == INF) break;
        int ds = INF;
        v = sk;
        while(prv[v] != -1){
            num = prv[v];
            ds = min(ds, ee[num].cn - ee[num].f);
            v = ee[num].v;
        }
        v = sk;
        while(prv[v] != -1){
            num = prv[v];
            ee[num].f += ds;
            ee[ee[num].p].f -= ds;
            v = ee[num].v;
        }
    }
}

void solve(){
    int n;
	cin >> n;
	string s;
	cin >> s;
	int m;
	cin >> m;
	int mx = 0;
	for (int i = 0; i < m; i++) {
		cin >> t[i];
		cin >> p[i];
		mx = max(p[i], mx);
		string tt = t[i] + "$" + s;
		z_function(tt);
		for (int j = 0, k = t[i].length() + 1; j < s.length(); j++, k++) {
			if (z[k] == t[i].length()) {
				has[i][j] = 1;
				dout << "(" << i << " " << j << ") ";
			}
		}
		dout << endl;
	}
	int x;
	cin >> x;
    int sr = n + 1;
    int sk = n + 2;
    int n2 = sk + 1;
    mx = 0;
    add_edge(sr, 0, x, mx);
    for(int i = 0; i < n; i++){
        add_edge(i, i + 1, x, mx);
    }
    add_edge(n, sk, x, mx);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(has[j][i]){
                add_edge(i, i + (int)t[j].length(), 1, mx - p[j]);
            }
        }
    }
    max_flow(sr, sk, n2);
    ll ans = 0;
    for(int i = 0; i < cnt; i++){
        if(ee[i].f > 0){
            ans += ee[i].cs - mx;
        }
    }
    cout << -ans;
}

int main() {
    #ifdef NASTYA
        assert(freopen("input.txt", "r", stdin)); assert(freopen("output.txt", "w", stdout));
    #else
     //assert(freopen(file".in", "r", stdin)); assert(freopen(file".out", "w", stdout));
    #endif
    int t = 1;
    while(t--) {
        solve();
    }
    return 0;
}