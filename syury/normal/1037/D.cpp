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

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef long double dbl;

const int maxn = 2e5 + 5;

void no(){
	cout << "No";
	exit(0);
}

vector<int> gr[maxn];
int level[maxn];
int with[maxn];
int n;
int a[maxn];

signed main(){
	sync;
	cin >> n;
	F(i, 0, n - 1){
		int v, u;
		cin >> v >> u;
		--v; --u;
		gr[v].pb(u);
		gr[u].pb(v);
	}
	fill(level, level + n, -1);
	F(i, 0, n){cin >> a[i]; --a[i];}
	with[0] = 1;
	level[0] = 0;
	int cl = 0;
	int cid = 1;
	F(i, 0, n){
		if(level[a[i]] != cl){no();}
		--with[level[a[i]]];
		bool w = false;
		I(u, gr[a[i]]){
			if(level[u] == -1){w = true; level[u] = cid; with[cid]++;}
		}
		if(w)++cid;
		if(with[cl] == 0)++cl;
	}
	cout << "Yes";
	ret 0;
}