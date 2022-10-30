//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,mmx,popcnt")

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

const int N = (int)3e5 + 5;

struct huy{
	int x, y, i;
	bool operator < (const huy & h)const{
		return x - y < h.x - h.y;
	}
};

int n, m;
huy a[N];
int ps[N];
ll px[N], py[N];
vector<int> bad[N];
ll ans[N];

signed main() {
	sync;
	cin >> n >> m;
	F(i, 0, n){
		int x, y;
		cin >> x >> y;
		a[i] = {x, y, i};
	}
	F(i, 0, m){
		int v, u;
		cin >> v >> u;
		--v; --u;
		bad[v].pb(u);
		bad[u].pb(v);
	}
	sort(a, a + n);
	F(i, 0, n){
		ps[a[i].i] = i;
		px[i] = (i == 0) ? 0 : px[i - 1];
		px[i] += a[i].x;
	}
	DF(i, n - 1, 0){
		py[i] = (i == n - 1) ? 0: py[i + 1];
		py[i] += a[i].y;
	}
	F(i, 0, n){
		ll l = i ? px[i - 1] : 0;
		ll r = (i + 1 < n) ? py[i + 1] : 0;
		ll ls = i, rs = n - 1 - i;
		ans[a[i].i] = l + r + a[i].y * ls + a[i].x * rs;
		int v = a[i].i;
		I(u, bad[v]){
			int j = ps[u];
			if(j < i){ans[a[i].i] -= a[i].y + a[j].x;}
			else ans[a[i].i] -= a[i].x + a[j].y;
		}
	}
	F(i, 0, n)cout << ans[i] << ' ';
	return 0;
}