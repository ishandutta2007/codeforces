#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,tune=native")
#include<bits/stdc++.h>

using namespace std;

#define I(x, a) for(auto x : (a))
#define all(x) (x).begin(),(x).end()
#define F(i, l, r) for(auto i = (l); i < (r); i++)
#define DF(i, l, r) for(auto i = (l); i >= (r); i--)
#define E(i, l, r) for(auto i = (l); i <= (r); i++)
#define pb push_back
#define X first
#define Y second
#define mp make_pair
#define ret return
#define brk break
#define cont continue

typedef long long ll;
typedef long double dbl;
typedef pair<int, int> pii;
typedef unsigned long long ull;

const int N = 5005;
const int A = (int)1e6 + 1;

int S[A];
vector<pii> add[A];
int a[N];
int p[A];
int sz[A];
int n, k;

int find_set(int v){
	return v == p[v] ? v : p[v] = find_set(p[v]);
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	F(i, 0, n)cin >> a[i];
	sort(a, a + n);
	F(i, 0, n){
		F(j, i + 1, n){
			int m = a[j] - a[i];
			++S[m];
			//add[m].pb(mp(a[i], a[j]));
		}
	}
	fill(sz, sz + A, 1);
	iota(p, p + A, 0);
	F(x, 1, A){
		//vector<int> changed;
		int kek = 0;
		#pragma GCC ivdep
		for(int y = x; y < A; y += x)kek += S[y];
		if(kek > k * (k + 1)/2)cont;
		/*for(int y = x; y < A; y += x){
			I(e, add[y]){
				int v = find_set(e.X), u = find_set(e.Y);
				if(v != u){
					int base = sz[v] > sz[u] ? v : u;
					p[v] = p[u] = base;
					sz[base] = sz[v] + sz[u];
					if(v != base)changed.push_back(v);
					if(u != base)changed.push_back(u);
				}
				if(changed.size() > k)break;
			}
			if(changed.size() > k)break;
		}
		I(v, changed){p[v] = v; sz[v] = 1;}
		if(changed.size() <= k){cout << x; return 0;}*/
		kek = 0;
		for(int i = 0; i < n; i++){
			if(p[a[i]%x] == x)++kek;
			if(kek > k)break;
			p[a[i]%x] = x;
		}
		if(kek <= k){cout << x; return 0;}
	}
	return 0;
}