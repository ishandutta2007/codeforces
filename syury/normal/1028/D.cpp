#include <bits/stdc++.h>

using namespace std;

#define sqr(x) ((x) * (x))
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define fin(name) auto varfin=freopen(name, "r", stdin);varfin=varfin
#define fout(name) auto varfout=freopen(name, "w", stdout);varfout=varfout
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
typedef pair <int32_t, int32_t> pii;

const int maxn = 363310;
const int mod = (int)1e9 + 7;

int32_t mx[4 * maxn], mi[4 * maxn];
int32_t who[maxn];
map<int32_t, int32_t> ss, ff;
int n;

void build(int v, int l, int r){
	if(l == r){mx[v] = mi[v] = who[l]; if(who[l] == -1){mx[v] = -mod; mi[v] = mod;}ret;}
	int mid = (l + r)/2;
	build(2*v, l, mid);
	build(2*v + 1, mid + 1, r);
	mx[v] = max(mx[2*v + 1], mx[2*v]);
	mi[v] = min(mi[2*v + 1], mi[2*v]);
}

int gmi(int v, int l, int r, int ul, int ur){
	if(ul > ur)ret mod;
	if(l == ul && r == ur)ret mi[v];
	int mid = (l + r)/2;
	ret min(gmi(2*v, l, mid, ul, min(ur, mid)), gmi(2*v + 1, mid + 1, r, max(ul, mid + 1), ur));
}

int gmx(int v, int l, int r, int ul, int ur){
	if(ul > ur)ret -mod;
	if(l == ul && r == ur)ret mx[v];
	int mid = (l + r)/2;
	ret max(gmx(2*v, l, mid, ul, min(ur, mid)), gmx(2*v + 1, mid + 1, r, max(ul, mid + 1), ur));
}

int main() {
    sync;
	cin >> n;
	F(i, 0, n){
		string s;
		int p;
		cin >> s >> p;
		who[i] = s.length() == 6u ? p : -1;
		if(s.length() == 3u){
			ss[p] = i;
		}
		else{
			ff[p] = i;
		}
	}
	I(x, ss)if(!ff.count(x.X)){ff[x.X] = n;}
	build(1, 0, n - 1);
	auto it = ss.begin(), jt = ff.begin();
	ll ans = 1;
	vector<pair<int, int> > check;
	while(it != ss.end()){
		int l = it->Y, r = jt->Y, p = it->X;
		++it; ++jt;
		int L = gmi(1, 0, n - 1, l, min(n - 1, r)), R = gmx(1, 0, n - 1, l, min(n - 1, r));
		bool bl = R <= p, wh = L >= p;
		if(!bl && !wh){cout << 0; ret 0;}
		int kek = 0;
		if(bl)kek |= 2;
		if(wh)kek |= 1;
		if(r == n){check.pb(mp(p, kek)); cont;}
		ans *= (int)bl + (int)wh;
		ans %= mod;
	}
	sort(all(check));
	ll mul = 0;
	n = check.size();
	int rw = 0, lw = n - 1;
	while(rw < n && check[rw].Y&1)++rw;
	while(lw >= 0 && check[lw].Y&2)--lw;
	F(before, 0, n + 1){
		if(rw >= before && lw < before)mul++;
	}
	cout << ans*mul%mod << endl;
    return 0;
}