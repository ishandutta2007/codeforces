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

struct item{
	ll x, y, pref, suff, tot;
	bool operator < (const item & it)const{
		return x < it.x;
	}
};

const int N = (int)3e5 + 5;

int n;
set<item> s;
pii ss[N];
ll a[N];
ll d[N];

int main(){
/*#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif*/
	sync;
	int C;
	cin >> n >> C;
	ll ans = 0;
	F(i, 0, n){
		cin >> d[i];
		cin >> a[i];
		a[i] = C - a[i];
		ans = max(ans, a[i]);
	}
	F(i, 1, n)
		ss[i - 1] = {i - 1, i};
	sort(ss, ss + n - 1, [&d](pii l, pii r){
				return d[l.Y] - d[l.X] < d[r.Y] - d[r.X];
			});
	F(j, 0, n - 1){
		int i = ss[j].X;
		ll delta = (d[i + 1] - d[i]) * (d[i + 1] - d[i]);
		item curr{i, i + 1, max({0ll, a[i], a[i] + a[i + 1]}), max({0ll, a[i + 1], a[i] + a[i + 1]}), a[i] + a[i + 1]};
		ans = max(ans, a[i] + a[i + 1] - delta);
		if(s.empty()){
			s.insert(curr);
			cont;
		}
		auto ri = s.upper_bound(curr);
		auto li = ri;
		if(li != s.begin())
			--li;
		else
			li = s.end();
		if((li != s.end() && li->y == i) && (ri != s.end() && ri->x - 1 == i)){
			curr.x = li->x;
			curr.y = ri->y;
			ans = max(ans, li->suff + ri->pref - delta);
			curr.pref = max(li->pref, li->tot + ri->pref);
			curr.suff = max(ri->suff, ri->tot + li->suff);
			curr.tot = li->tot + ri->tot;
			auto rr = *ri;
			s.erase(li);
			s.erase(rr);
			s.insert(curr);
			continue;
		}
		if(li != s.end() && li->y == i){
			curr.x = li->x;
			curr.y = i + 1;
			ans = max(ans, li->suff + a[i + 1] - delta);
			curr.pref = max(li->pref, li->tot + a[i + 1]);
			curr.suff = max(0ll, li->suff + a[i + 1]);
			curr.tot = li->tot + a[i + 1];
			s.erase(li);
			s.insert(curr);
			continue;
		}
		if(ri != s.end() && ri->x - 1 == i){
			curr.x = i;
			curr.y = ri->y;
			ans = max(ans, ri->pref + a[i] - delta);
			curr.pref = max(0ll, ri->pref + a[i]);
			curr.suff = max(ri->suff, ri->tot + a[i]);
			curr.tot = a[i] + ri->tot;
			s.erase(ri);
			s.insert(curr);
			continue;
		}
		s.insert(curr);
	}
	cout << ans;
	return 0;
}