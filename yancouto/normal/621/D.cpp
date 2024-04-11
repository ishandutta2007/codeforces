#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<long double, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

string form[] = {
	"x^y^z",
	"x^z^y",
	"(x^y)^z",
	"(x^y)^z",
	"y^x^z",
	"y^z^x",
	"(y^x)^z",
	"(y^x)^z",
	"z^x^y",
	"z^y^x",
	"(z^x)^y",
	"(z^x)^y"
};


typedef long double ld;
ld lg(ld x) {
	if(abs(x) <= 1e-9) return ld(-1/0.);
	return log(x);
}
vector<pii> v[3];
inline void V(int i, int s, ld x) {
	v[s].pb(pii(x, -i));
}
inline int sign(ld x) {
	if(x < 1) return 0;
	else if(x > 1) return 2;
	else return 1;
}
int main() {
	ld x, y, z; int i;
	double xx, yy, zz;
	scanf("%lf %lf %lf", &xx, &yy, &zz);
	x = xx; y = yy; z = zz;
	V( 0, sign(x), z*lg(y) + lg(abs(lg(x))));
	V( 1, sign(x), y*lg(z) + lg(abs(lg(x))));
	V( 2, sign(x), lg(z*y) + lg(abs(lg(x))));
	V( 3, sign(x), lg(z*y) + lg(abs(lg(x))));
	V( 4, sign(y), z*lg(x) + lg(abs(lg(y))));
	V( 5, sign(y), x*lg(z) + lg(abs(lg(y))));
	V( 6, sign(y), lg(z*x) + lg(abs(lg(y))));
	V( 7, sign(y), lg(z*x) + lg(abs(lg(y))));
	V( 8, sign(z), y*lg(x) + lg(abs(lg(z))));
	V( 9, sign(z), x*lg(y) + lg(abs(lg(z))));
	V(10, sign(z), lg(y*x) + lg(abs(lg(z))));
	V(11, sign(z), lg(y*x) + lg(abs(lg(z))));
	if(!v[2].empty()) {
		pii k = *max_element(v[2].begin(), v[2].end());
		puts(form[-k.snd].c_str());
	} else if(!v[1].empty()) {
		int j = INT_MAX;
		for(i = 0; i < v[1].size(); i++)
			j = min(j, -v[1][i].snd);
		puts(form[j].c_str());
	} else {
		sort(v[0].begin(), v[0].end());
		for(i = 0; i + 1 < 12; i++)
			if(abs(v[0][i + 1].fst - v[0][i].fst) > 1e-9)
				break;
		puts(form[-v[0][i].snd].c_str());
	}
}