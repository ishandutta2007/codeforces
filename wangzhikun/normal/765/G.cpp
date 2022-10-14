//
#include <bits/stdc++.h>
#define ll long long
#define maxn 500005 /*rem*/
#define mod 1000000007
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
struct edge {
	ll a;
	int b;
	edge *next;
};
const int md = 10000007;
struct th {
	edge p[10000005];
	edge *h[md];
	int sz;
	th(){sz = 0;}
	void push(ll a, int b) {
		edge *cur = &p[sz++];
		cur->a = a, cur->b = b, cur->next = h[a % md], h[a % md] = cur;
	}
	ll q(ll a) {
		for (edge *p = h[a % md]; p; p = p->next)
			if (p->a == a) return p->b;
		return 0;
	}
};
th dp;
char inp[maxn];
ll s;
int n;
vi u, v;
vector<vector<ll> >msk; 
ll d[maxn][50];
int m;
int cal(ll a, int l, int r) {
	ll cur = (1ll << (r + 1)) - 1;
	ll c2 = (1ll << (l)) - 1;
	return __builtin_popcountll(a & (cur ^ c2));
}
void initmsk(int id) {
	int fl = 0;
	int cl = m - 1 - u[id], cr = u[id];
	if (cl < cr) fl = 1;
	for (int j = 0; j < u[id]; j++) {
		ll g = 0;
		for (int i = 0; i < m; i++)
			if ((i + j) % u[id] == 0)
				g ^= (1ll << i);
		if ((s & g) != g) continue;
		if (fl && ((u[id] - j) % u[id] > cl)) continue;
		else 
			msk[id].pb(g);
	}
}
ll gt(int l, int r) {
	return ((1ll << (r + 1)) - 1) ^ ((1ll << (l)) - 1);
}
//int tms = 0;
int sz[30];
ll cur[16][50];
int work(int a, ll sta) {
	
	if ((sta & s) != sta) return 0;	
	if (a == u.size()) 
		return d[0][__builtin_popcountll(sta)];
	int cl = m - 1 - u[a], cr = u[a]; // >= cr <= cl 
	int cn;
	if (cl < cr) {
		// regular
		int cn = cal(sta, cl + 1, cr - 1); 
		sta ^= (sta & gt(cl + 1, cr - 1));
		sta ^= cur[a][cn];
	} 
	ll id = sta * 15 + a;
	ll c1 = dp.q(id);
	if (c1) return c1 - 1;	
	ll cur = 0;
	sz[a]++;
	for (auto k : msk[a])
		cur += 1ll * work(a + 1, sta | k);//, cout << "??" << k << endl;
	if (cl < cr) {
		int tot = cal(s, cl + 1, cr - 1);
		cn = cal(sta, cl + 1, cr - 1); 
		ll y;
		for (int i = cl + 1; i <= cr - 1; i++) {
			ll u = 1ll << i;
			if ((s & u) && !(sta & u)) {
				y = u;
				break;
			}
		}
		if (cn) cur += 1ll * cn * work(a + 1, sta);
		if (tot - cn) cur += 1ll * (tot - cn) * work(a + 1, sta | y);
	}
	cur %= mod;
	dp.push(id, cur + 1);
	return cur;
}
int main() {
	scanf("%s", inp);
	m = strlen(inp);
	int cnt = 0;
	for (int j = 0; j < m; j++)
		if (inp[j] == '0') s += 1ll << j, cnt++;
	scanf("%d", &n);
	ll bg = 1;
	for (int i = 0; i < n; i++) {
		int p, a;
		scanf("%d%d", &p, &a);
		bg = bg * ksm(p, a - 1) % mod;
		if (p < m) u.pb(p);
		else v.pb(p);
	}
	sort(u.begin(), u.end());
//	for (int i = 1; i < u.size() - 1; i++)
//		assert(u[i] != u[i - 1]);
	sort(v.begin(), v.end());
	msk.resize(u.size());
	for (int i = 0; i < u.size(); i++)
		initmsk(i);
	for (int a = 0; a < u.size(); a++) {
		int cl = m - 1 - u[a], cr = u[a];
		for (int cn = 0; cn <= 40; cn++) {
			ll uu = 0;
			int q = cn;
			for (int j = cl + 1; j <= cr - 1; j++)
				if (s & (1ll << j))
					if (q) uu ^= (1ll << j), q--;
			cur[a][cn] = uu;
		}
	}
//	cout << "AF" << endl;
	for (int i = v.size(); i >= 0; i--)
		for (int j = 0; j <= cnt; j++) {
			if (i == v.size()) {
				if (j == cnt) d[i][j] = 1;
				else d[i][j] = 0; 
			} 
			else {
				ll cur = d[i + 1][j] * (v[i] - (m - j));
				cur += d[i + 1][j + 1] * (cnt - j);
				cur %= mod;
				d[i][j] = cur;
			}
		}
		
	ll ans = work(0, 0);
	ans = ans * bg % mod;
	if (ans < 0) ans += mod;
	cout << ans << endl;
	return 0;
}