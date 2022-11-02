#include<bits/stdc++.h>
#include<bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define F(i, l, r) for(int i = (l); i < (r); i++)
#define E(i, l, r) for(int i = (l); i <= (r); i++)
#define DF(i, l, r) for(int i = (l); i >= (r); i--)
#define I(x, a) for(auto x : (a))
#define mp make_pair
#define X first
#define Y second
#define clean(x) memset((x), 0, sizeof(x))
#define ret return
#define cont continue
#define brk break
#define ins insert
#define all(x) (x).begin(),(x).end()
#define sync ios_base::sync_with_stdio(false);cin.tie(0)
#define pb push_back
#define y1 fjfg
#define tm shjfhg

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

const int N = (int)1e3 + 3;

int n, m;
int comps = 0;
int base[N];
int val[N];
bool used[N];
int diam[N];
int d[N];
vector<int> comp[N];
vector<int> gr[N];

void dfs(int v){
	used[v] = 1;
	comp[comps].pb(v);
	I(u, gr[v])
		if(!used[u])
			dfs(u);
}

int bfs(int st){
	d[st] = 0;
	int ans = 0;
	queue<int> q;
	q.push(st);
	while(!q.empty()){
		int v = q.front();
		ans = max(ans, d[v]);
		q.pop();
		I(u, gr[v])
			if(d[u] == -1){
				d[u] = d[v] + 1;
				q.push(u);
			}
	}
	return ans;
}

void process(int id){
	base[id] = -1;
	int old_score;
	I(v, comp[id]){
		fill(d, d + N, -1);
		int curr = bfs(v);
		diam[id] = max(diam[id], curr);
		if(base[id] == -1 || old_score > curr){
			base[id] = v;
			old_score = curr;
		}
	}
	val[id] = old_score;
}

signed main() {
	sync;
	cin >> n >> m;
	F(i, 0, m){
		int v, u;
		cin >> v >> u;
		--v; --u;
		gr[v].pb(u);
		gr[u].pb(v);
	}
	F(i, 0, n){
		if(used[i])
			cont;
		dfs(i);
		process(comps);
		++comps;
	}
	if(comps == 1){
		cout << diam[0];
		return 0;
	}
	int ans = (int)1e9;
	int pos;
	F(id, 0, comps){
		int curr = 0;
		int m1 = -1, m2 = -1;
		F(i, 0, comps){
			if(i == id)cont;
			curr = max(curr, 1 + val[id] + val[i]);
			if(val[i] > m1){
				m2 = m1;
				m1 = val[i];
			}
			else if (val[i] > m2)m2 = val[i];
		}
		if(m2 != -1)
			curr = max(curr, 2 + m1 + m2);
		if(ans > curr){
			ans = curr;
			pos = id;
		}
	}
	F(i, 0, comps)ans = max(ans, diam[i]);
	cout << ans << '\n';
	F(i, 0, comps){
		if(i != pos)
			cout << base[i] + 1 << ' ' << base[pos] + 1 << '\n';
	}
	return 0;
}