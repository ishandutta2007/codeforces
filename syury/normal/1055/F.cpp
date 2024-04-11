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

const int N = (int)1e6 + 6;

int n;
ll k;
ull a[N];
vector<pair<int, ull> > gr[N];
int32_t tpos[N];
int32_t vpos[N];
int32_t sub[N];
int32_t out[N][2];
int sz = 1;

void dfs(int v, ull carry){
	a[v] = carry;
	I(e, gr[v]){
		dfs(e.X, carry^e.Y);
	}
}

inline int32_t make_node(){
	sub[sz] = 0;
	ret sz++;
}

inline ll get(ull x, int bit){
	ll ans = 0;
	F(i, 0, n){
		int d;
		if((x&(1ull<<bit)) == (a[i]&(1ull<<bit)))
			d = 0;
		else
			d = 1;
		if(tpos[i] != -1 && out[tpos[i]][d] != -1)
			ans += sub[out[tpos[i]][d]];
	}
	ret ans;
}

inline void push(int bit){
	sz = 0;
	F(i, 0, n){
		int d = (a[i]&(1ull<<bit)) ? 1 : 0;
		if(out[vpos[i]][d] == -1)out[vpos[i]][d] = make_node();
		vpos[i] = out[vpos[i]][d];
		++sub[vpos[i]];
	}
}

inline void adv(ull x, int bit){
	F(i, 0, n){
		int d;
		if((x&(1ull<<bit)) == (a[i]&(1ull<<bit)))
			d = 0;
		else
			d = 1;
		if(tpos[i] != -1)
			tpos[i] = out[tpos[i]][d];
	}
	F(i, 0, sz)out[i][0] = out[i][1] = -1;
}

signed main(){
	sync;
	out[0][0] = out[0][1] = -1;
	cin >> n >> k;
	F(i, 1, n){
		int p;
		ull w;
		cin >> p >> w;
		--p;
		gr[p].pb({i, w});
	}
	dfs(0, 0);
	F(i, 0, n)
		gr[i].clear();
	--k;
	sub[0] = n;
	F(i, 0, n)tpos[i] = vpos[i] = 0;
	ull got = 0;
	DF(bit, 61, 0){
		push(bit);
		ll cu = get(got, bit);
		if(cu <= k){
			k -= cu;
			got |= 1ull<<bit;
			adv(got, bit);
		}
		else{
			adv(got, bit);
		}
	}
	cout << got;
	ret 0;
}