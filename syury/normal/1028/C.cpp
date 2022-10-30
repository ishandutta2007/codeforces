#pragma GCC optimize("Ofast")

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
typedef long double dbl;
typedef pair <int, int> pii;

const int maxn = (int)3e5 + 5;

pii l[maxn], r[maxn];
int n;

signed main() {
    sync;
	cin >> n;
	set<int, greater<int> > x;
	set<int> y;
	F(i, 0, n){
		cin >> l[i].X >> l[i].Y >> r[i].X >> r[i].Y;
		x.insert(l[i].X);
		y.insert(r[i].Y);
	}
	int c = 3;
	vector<int> tx, ty;
	auto it = x.begin();
	while(c && it != x.end()){
		tx.pb(*it);
		++it;
		--c;
	}
	c = 3;
	auto jt = y.begin();
	while(c && jt != y.end()){
		ty.pb(*jt);
		++jt;
		--c;
	}
	I(cx, tx){
		I(cy, ty){
			int g = 0;
			F(i, 0, n){
				if(cx < l[i].X || cx > r[i].X || cy < l[i].Y || cy > r[i].Y){++g; if(g > 1)break;}
			}
			if(g < 2){
				cout << cx << ' ' << cy << endl;
				ret 0;
			}
		}
	}
    return 0;
}