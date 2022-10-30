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

const int maxn = 2e5 + 5;

int x[maxn];
int r[maxn];
int q[maxn];
int n, k;
int cid = 0;
int lpos[maxn], rpos[maxn];
int* tree[maxn];
vector<int> pos[maxn];
set<int> ayy;
map<int, int> lmao;
int lwb[maxn];
int pps[maxn];
int tot[maxn];

void add(int* t, int len, int pos, int d){
	while(pos <= len){
		t[pos] += d;
		pos += pos&-pos;
	}
}

int get(int* t, int r){
	if(r == 0)ret 0;
	int ans = 0;
	while(r){
		ans += t[r];
		r -= r&-r;
	}
	ret ans;
}

int main() {
    sync;
	cin >> n >> k;
	vector<pair<int, pii> > kek;
	F(i, 0, n){
		int a, b, c;
		cin >> a >> b >> c;
		kek.pb(mp(a, mp(b, c)));
	}
	sort(all(kek));
	F(i, 0, n){
		x[i] = kek[i].X;
		r[i] = kek[i].Y.X;
		q[i] = kek[i].Y.Y;
		ayy.ins(q[i]);
	}
	I(c, ayy){
		lmao[c] = cid++;
	}
	I(c, ayy){
		int l = c - k, r = c + k;
		auto lt = ayy.lower_bound(l);
		auto rt = ayy.upper_bound(r);
		int i = lmao[c];
		if(rt == ayy.begin()){rpos[i] = -1; cont;}
		--rt;
		int lp = *lt, rp = *rt;
		if(lp > rp){rpos[i] = -1; cont;}
		lpos[i] = lmao[lp];
		rpos[i] = lmao[rp];
	}
	F(i, 0, n){
		int p = lmao[q[i]];
		pps[i] = p;
		if(!pos[p].empty() && pos[p].back() == x[i])cont;
		pos[p].pb(x[i]);
	}
	F(i, 0, cid){
		int sz = pos[i].size();
		tree[i] = new int[sz + 1];
		fill(tree[i], tree[i] + 1 + sz, 0);
	}
	set<pii> s;
	ll ans = 0;
	F(i, 0, n){
		while(!s.empty() && s.begin()->X < x[i]){int p = pps[s.begin()->Y]; --tot[p]; add(tree[p], pos[p].size(), lwb[s.begin()->Y] + 1, -1); s.erase(s.begin());}
		int p = pps[i];
		F(j, lpos[p], rpos[p] + 1){
			int huy = lower_bound(all(pos[j]), x[i] - r[i]) - pos[j].begin();
			ans += tot[j] - get(tree[j], huy);
		}
		int j = lower_bound(all(pos[p]), x[i]) - pos[p].begin();
		lwb[i] = j;
		add(tree[p], pos[p].size(), j + 1, 1);
		++tot[p];
		s.insert(mp(x[i] + r[i], i));
	}
	cout << ans;
}