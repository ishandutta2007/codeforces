#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define I(x, a) for(auto x : a)
#define F(i, l, r) for(auto i = l; i < r; ++i)
#define E(i, l, r) for(auto i = l; i <= r; ++i)
#define DF(i, l, r) for(auto i = l; i >= r; --i)
#define clean(a) memset((a),0,sizeof (a))
#define sync ios_base::sync_with_stdio(0);cin.tie(0)
#define all(x) (x).begin(),(x).end()
#define ret return
#define cont continue
#define brk break
#define ins insert
#define sz(a) ((int)(a).size())

typedef long long ll;
typedef unsigned int ull;
typedef long double dbl;
typedef pair <int, int> pii;

#define short int16_t

template<size_t MAXN>
struct Kuhn{
	short match[MAXN];
	int used[MAXN];
	bool was[MAXN];
	short gr[MAXN][MAXN/2 + 22];
	short grp[MAXN];
	int n;
	int cc;
	Kuhn(){}
	Kuhn(int _n):n(_n){
		for(int i = 0; i < n; i++){
			match[i] = -1;
			used[i] = was[i] = 0;
		}
	}
	void resize(int _n){
		n = _n;
		for(int i = 0; i < n; i++){
			match[i] = -1;
			grp[i] = 0;
			used[i] = was[i] = 0;
		}
	}
	void add_edge(int v, int u){
//		gr[v].push_back(u);
//		gr[u].push_back(v);
		gr[v][grp[v]++] = u;
		gr[u][grp[u]++] = v;
		assert(grp[v] <= MAXN/2 + 22);
		assert(grp[u] <= MAXN/2 + 22);
	}
	bool dfs(int v){
		if(used[v] == cc)return false;
		used[v] = cc;
		for(int ii = 0; ii < grp[v]; ii++){
			auto u = gr[v][ii];
			if(match[u] == -1){
				was[v] = true;
				match[u] = v;
				return true;
			}
		}
		for(int ii = 0; ii < grp[v]; ii++){
			auto u = gr[v][ii];
			if(dfs(match[u])){
				was[v] = true;
				match[u] = v;
				return true;
			}
		}
		return false;
	}
	void solve(){
		cc = 0;
		for(int i = 0; i < n; i++){used[i] = 0; was[i] = false; match[i] = -1;}
		for(int run = 1; run;){
			cc++;
			run = 0;
			for(int i = 0; i < n; i++)used[i] = false;
			for(int i = 0; i < n; i++){
				if(!was[i] && dfs(i))run = 1;
			}
		}	
	}
};

const int maxn = 5e3 + 30;

struct item{
	int tp;
	vector<short> kek;
};

Kuhn<maxn * 2> solver;
int n, m;
//short edgesx[maxn * maxn];
//short edgesy[maxn * maxn];
short p[maxn];
//char w[maxn][maxn];
bool tou[maxn];
short us[maxn];
item it[maxn];
vector<short> who[maxn];

int find_set(int v){
	return v == p[v] ? v : p[v] = find_set(p[v]);
}

void unite(int v, int u){
	v = find_set(v);
	u = find_set(u);
	if(v == u)ret;
	p[v] = u;
}

inline void process_edge(int v, int u){
//	w[v][u - n] |= 2;
	//u = find_set(u - n);
//	if(w[v][u]&1)ret;
//	w[v][u] |= 1;
	solver.add_edge(v, u + n);
}

inline bool had(int v, int u){
	u += n;
	if(it[v].tp == 1){return it[v].kek[0] <= u && u <= it[v].kek[1];}
	I(x, it[v].kek)if(x == u)ret true;
	ret false;
}

int main() {
    sync;
	cin >> n >> m;
	F(i, 0, m)p[i] = i;
	solver.resize(n + m);
	int ans = 0;
	set<int> dcp;
	F(i, 0, n){
		int tp;
		cin >> tp;
		it[i].tp = tp;
		it[i].kek.clear();
		if(tp == 0){
			int k;
			cin >> k;
			it[i].tp = tp;
			dcp.clear();
			F(j, 0, k){
				int u;
				cin >> u;
				--u;
				if(dcp.count(u))cont;
				dcp.insert(u);
				it[i].kek.pb(u + n);
				//solver->add_edge(i, u + n);
				//edgesx[ptr] = i;
				//edgesy[ptr++] = u + n;
			}
		}
		if(tp == 1){
			int l, r;
			cin >> l >> r;
			--l; --r;
			//F(j, l, r + 1)solver->add_edge(i, j + n);
			//F(j, l, r + 1){edgesx[ptr] = i; edgesy[ptr++] = j + n;}
			it[i].kek.pb(l + n); it[i].kek.pb(r + n);
		}
		if(tp == 2){
			int a, b, c;
			cin >> a >> b >> c;
			--a; --b; --c;
			us[a] = us[b] = us[c] = i;
			unite(a, c);
			unite(a, b);
			ans += 2;
		}
	}
	F(j, 0, m)who[j].clear();
	/*solver.s = n + m;
	solver.t = n + m + 1;
	F(i, 0, n)solver.add_edge(n + m, i, 1);
	F(j, 0, m)solver.add_edge(j + n, n + m + 1, 1);*/
	F(j, 0, m){
		who[find_set(j)].pb(j);
	}
	vector<char> kekk(m);
	F(i, 0, n){
		if(it[i].tp == 2)cont;
		kekk.assign(m, false);
		if(it[i].tp == 0){
			I(j, it[i].kek){
			int jj = find_set(j - n);
			if(kekk[jj])cont;
			kekk[jj] = true;
			process_edge(i, jj);
		}
		}
		if(it[i].tp == 1)F(j, it[i].kek[0], it[i].kek[1] + 1){
			int jj = find_set(j - n);
			if(kekk[jj])cont;
			kekk[jj] = true;
			process_edge(i, jj);
		}
//		vector<short>().swap(it[i].kek);
	}
	solver.solve();
	//F(i, 0, n + m)vector<short>().swap(solver.gr[i]);
	vector<pii> out;
	F(v, 0, n){
		if(solver.match[v] == -1)cont;
		++ans;
		int u = solver.match[v] - n;
		//cout << e.v << " " << e.u << " " << e.flow << endl;
		int kik = find_set(u);
		bool g = false;
		I(uu, who[kik]){if(!tou[uu] && had(v, uu)){out.pb(mp(v, uu)); tou[uu] = true; g = true; break;}}
		//assert(it[v].tp != 2);
		//assert(g || it[v].tp == 0);
	}
	F(j, 0, m){
		if(who[j].size() <= 1u)cont;
		int cc = 0;
		I(x, who[j]){
			if(tou[x])cont;
			++cc;
			out.pb(mp(us[x], x));
			if(cc == 2)break;
		}
		//assert(cc == 2);
	}
	cout << out.size() << endl;
	//assert((int)out.size() == ans);
	I(x, out)cout << x.X + 1 << ' ' << x.Y + 1 << '\n';
}