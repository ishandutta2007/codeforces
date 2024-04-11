#include <bits/stdc++.h>//////////////////////////////////////////////////////
#ifdef LOC////////////////////////////////////////////////////////////////////
#include "debuglib.h"/////////////////////////////////////////////////////////
#else/////////////////////////////////////////////////////////////////////////
#define deb(...)//////////////////////////////////////////////////////////////
#define DBP(...)//////////////////////////////////////////////////////////////
#endif////////////////////////////////////////////////////////////////////////
#define x first///////////////////////////////////////////////////////////////
#define y second//////////////////////////////////////////////////////////////
#define mp make_pair//////////////////////////////////////////////////////////
#define pb push_back//////////////////////////////////////////////////////////
#define sz(x)int((x).size())//////////////////////////////////////////////////
#define each(a,x)for(auto&a:(x))///////////////// by teapotd /////////////////
#define all(x)(x).begin(),(x).end()///////////////////////////////////////////
#define rep(i,b,e)for(int i=(b);i<(e);i++)////////////////////////////////////
using namespace std;using namespace rel_ops;using ll=int64_t;using Pii=pair///
<int,int>;using ull=uint64_t;using Vi=vector<int>;void run();int main(){cin.//
sync_with_stdio(0);cin.tie(0);cout<<fixed<<setprecision(10);run();return 0;}//
//--------------------------------------------------------------------------//

using Point = pair<ll, ll>;

ll sY, a, b;
int n;

vector<Point> segments;
vector<ll> prefs;
Point cur;

double proj(Point point, ll x) {
	double alfa = double(point.x - x) / double(point.y);
	return alfa*double(sY) + double(x);
}

bool projCmp(Point l, ll val) {
	return (cur.x-l.y)*sY + l.y*cur.y < val*cur.y;
}

void handle() {
	cin >> cur.x >> cur.y;

	int begin = int(lower_bound(all(segments), a, projCmp) - segments.begin());
	int end = int(lower_bound(all(segments), b, projCmp) - segments.begin());

	double ret = double(prefs[end] - prefs[begin]) * double(cur.y-sY) / double(cur.y);

	if (begin < n) {
		ret -= max(double(a) - proj(cur, segments[begin].x), 0.0);
	}
	if (end < n) {
		ret += max(double(b) - proj(cur, segments[end].x), 0.0);
	}

	cout << ret << '\n';
}

void run() {
	cin >> sY >> a >> b >> n;
	segments.resize(n);
	prefs.pb(0);

	each(s, segments) {
		cin >> s.x >> s.y;
		prefs.pb(prefs.back() + s.y-s.x);
	}

	int q; cin >> q;
	while (q--) handle();
}