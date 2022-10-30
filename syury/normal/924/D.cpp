#include<bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

#define F(i, l, r) for(int i = (l); i < (r); i++)
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

#define int long long

const int maxn = 1e5 + 5;

struct rational{
	ll x;
	ll y;
};

bool operator < (const rational & l, const rational & r){
	//cout << "HI" << endl;
	ll kek = l.y * r.y;
	ll lp = l.x * r.y, rp = r.x * l.y;
	if(lp == rp)return false;
	bool ans = lp < rp;
	if(kek < 0)ans = !ans;
//	cout << kek << " " << lp << " " << rp << " " << ans << endl;
	return ans;
}

bool operator == (const rational & l, const rational & r){
	return !(l < r || r < l);
}

int n, w;
int cid = 0;
int x[maxn];
int v[maxn];
pair<rational, rational> f[maxn];
set<rational> rs;
map<rational, int> kekmap;
int t[maxn];

void inc(int pos){
	++pos;
	while(pos < maxn){
		++t[pos];
		pos += pos&-pos;
	}
}

int get(int pos){
	++pos;
	int res = 0;
	while(pos){
		res += t[pos];
		pos -= pos&-pos;
	}
	return res;
}

signed main(){
	sync;
	cin >> n >> w;
	F(i, 0, n){cin >> x[i] >> v[i];}
	F(i, 0, n){
		rational low = {llabs(x[i]), llabs(v[i] - w)};
		rational hi = {llabs(x[i]), llabs(v[i] + w)};
		rs.insert(hi);
		f[i] = {low, hi};
	//	cout << f[i].X.X << " " << f[i].X.Y << " ; " << f[i].Y.X << " " << f[i].Y.Y << endl;
	}
	I(r, rs)kekmap[r] = cid++;
	sort(f, f + n);
	ll ans = 0;
	//if(f[0].X < f[1].X)cout << "KEK" << endl;
	rational last_x;
	int lend = -1;
	F(i, 0, n){
		//cout << f[i].X.x << " " << f[i].X.y << " ; " << f[i].Y.x << " " << f[i].Y.y << endl;
		int j = kekmap[f[i].Y];
		//cout << j << endl;
		if(i > 0 && last_x == f[i].X){
			ans += i - lend - 1;
		}
		else{
			//cout << i << " " << lend << endl;
			F(j, lend + 1, i){
				int k = kekmap[f[j].Y];
				inc(cid - 1 - k);
			}
			lend = i - 1;
			last_x = f[i].X;
		}
		ans += get(cid - 1 - j);
		//inc(cid - 1 - j);
	}
	cout << ans;
	ret 0;
}