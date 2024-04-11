#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define l log
#define p pow
typedef long double ld;

struct E {
	string s;
	ld val;
	E(string ss="", ld v=0) {
		s = ss;
		val = v;
	}
	bool operator<(E o) const { return val>o.val; }
};

ld x,y,z;
vector<E> h;

int main() {
	cin >> x >> y >> z;
	if (max(max(x,y),z)>1.01) {
		if (x>1.01) h.pb(E("x^y^z",l(l(x))+l(y)*z));
		if (x>1.01) h.pb(E("x^z^y",l(l(x))+l(z)*y));
		if (x>1.01) h.pb(E("(x^y)^z",l(l(x))+l(y*z)));
		if (y>1.01) h.pb(E("y^x^z",l(l(y))+l(x)*z));
		if (y>1.01) h.pb(E("y^z^x",l(l(y))+l(z)*x));
		if (y>1.01) h.pb(E("(y^x)^z",l(l(y))+l(z*x)));
		if (z>1.01) h.pb(E("z^x^y",l(l(z))+l(x)*y));
		if (z>1.01) h.pb(E("z^y^x",l(l(z))+l(y)*x));
		if (z>1.01) h.pb(E("(z^x)^y",l(l(z))+l(x*y)));
	} else {
		h.pb(E("x^y^z",p(x,p(y,z))));
		h.pb(E("x^z^y",p(x,p(z,y))));
		h.pb(E("(x^y)^z",p(x,y*z)));
		h.pb(E("y^x^z",p(y,p(x,z))));
		h.pb(E("y^z^x",p(y,p(z,x))));
		h.pb(E("(y^x)^z",p(y,z*x)));
		h.pb(E("z^x^y",p(z,p(x,y))));
		h.pb(E("z^y^x",p(z,p(y,x))));
		h.pb(E("(z^x)^y",p(z,x*y)));
	}
	stable_sort(h.begin(),h.end());
	cout << h[0].s;
}