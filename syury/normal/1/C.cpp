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

int main() {
    sync;
	pair<dbl, dbl> p[3];
	F(i, 0, 3)cin >> p[i].X >> p[i].Y;
	dbl l0 = (p[2].X - p[1].X) * (p[2].X - p[1].X) + (p[2].Y - p[1].Y) * (p[2].Y - p[1].Y);
	dbl l1 = (p[2].X - p[0].X) * (p[2].X - p[0].X) + (p[2].Y - p[0].Y) * (p[2].Y - p[0].Y);
	dbl l2 = (p[0].X - p[1].X) * (p[0].X - p[1].X) + (p[0].Y - p[1].Y) * (p[0].Y - p[1].Y);
	dbl w0 = l0 * (l1 + l2 - l0), w1 = l1 * (l0 + l2 - l1), w2 = l2 * (l1 + l0 - l2);
	dbl x = (p[0].X * w0 + p[1].X * w1 + p[2].X * w2)/(w0 + w1 + w2), y = (p[0].Y * w0 + p[1].Y * w1 + p[2].Y * w2)/(w0 + w1 + w2);
	F(sides, 3, 101){
		bool g = true;
		F(i, 0, 3){
			dbl a1 = atan2(p[i].Y - y, p[i].X - x);
			F(j, i + 1, 3){
				dbl a2 = atan2(p[j].Y - y, p[j].X - x);
				dbl ang = fabs(a1 - a2);
				if(fabs(sin(ang * sides/2)) > 1e-4)g = false;
			}
		}
		if(g){
			dbl R = (p[0].X - x) * (p[0].X - x) + (p[0].Y - y) * (p[0].Y - y);
			cout.precision(15);
			cout << fixed << sides * 0.5 * R * sin(2 * acos(-1.0) / sides) << endl;
			ret 0;
		}
	}
	assert(false);
}