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

const int N = (int)1e5 + 5;

int n;
vector<int> out[N];
int sz[N];
int add[N];
int ans[N];

void dfs(int v){
	if(out[v].empty())sz[v] = 1;
	I(u, out[v]){
		dfs(u);
		sz[v] += sz[u];
	}
	add[sz[v]]++;
}

int main() {
    sync;
	cin >> n;
	F(i, 1, n){
		int p;
		cin >> p;
		--p;
		out[p].pb(i);
	}
	dfs(0);
	int curr = 0;
	int old = 0;
	F(i, 1, n + 1){
		curr += add[i];
		F(j, old + 1, curr + 1)ans[j] = i;
		old = curr;
	}
	F(i, 0, n)cout << ans[i + 1] << ' ';
	return 0;
}