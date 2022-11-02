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
typedef unsigned long long ull;
typedef long double dbl;
typedef pair <int, int> pii;

const int maxn = (int)2e5 + 5;

int n, m, k;
vector<pii> out[maxn];
int la[maxn];
int pos[maxn];
int deg[maxn];
int add[maxn];
bool dead[maxn];
set<pii, greater<pii> > s;

int main() {
    sync;
	cin >> n >> m >> k;
	fill(la, la + n, -1);
	F(i, 0, m){
		int v, u;
		cin >> v >> u;
		--v; --u;
		out[v].pb(mp(i, u));
		out[u].pb(mp(i, v));
		++deg[v]; ++deg[u];
		if(deg[v] == k){pos[v] = out[v].size() - 1; la[v] = i;}
		if(deg[u] == k){pos[u] = out[u].size() - 1; la[u] = i;}
	}
	F(i, 0, n)if(la[i] == -1)la[i] = m;
//	F(i, 0, n)cout << i << " " << la[i] << endl;
	F(i, 0, n)s.insert(mp(la[i], i));
	while(!s.empty()){
		int v = s.begin()->Y;
		dead[v] = true;
		s.erase(s.begin());
		I(e, out[v]){
			int u = e.Y;
			if(dead[u] || la[u] == la[v])cont;
			if(la[u] < e.X)cont;
			s.erase(mp(la[u], u));
			++pos[u];
			while(pos[u] != (int)out[u].size() && dead[out[u][pos[u]].Y])++pos[u];
			if(pos[u] == (int)out[u].size())la[u] = m;
			else la[u] = out[u][pos[u]].X;
			la[u] = min(la[u], la[v]);
			s.insert(mp(la[u], u));
		}
	}
	F(i, 0, n)add[la[i]]++;
	int curr = 0;
	F(i, 0, m){
		curr += add[i];
		cout << curr << '\n';
	}
    return 0;
}