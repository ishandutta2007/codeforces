#include <bits/stdc++.h>
#ifdef LOC
#define deb _deb
#else
#define deb(...)
#endif
#define x  first
#define y second
#define mp make_pair
#define pb push_back
#define sz(x)int((x).size())
#define each(a,x)for(auto&a:(x))
#define all(x)(x).begin(),(x).end()
#define rep(i,b,e)for(int i=(b);i<(e);i++)
#define tem template<class t,class u,class...w>
#define DBP(...)void print(...){DD(#__VA_ARGS__,__VA_ARGS__);}
#define pri(y)tem auto operator<<(t&o,u a)->decltype(y(a),o){return o<<
#define _deb(...)(DD("#, "#__VA_ARGS__,__LINE__,__VA_ARGS__),cerr<<endl)
using ll=long long;pri(a.print)"{",a.print(),o<<"}";}using namespace std;void DD(...){}using Pii=pair<int
,int>;tem void DD(t s,u a,w...k){while(*s&&*s!=',')cerr<<*s++;cerr<<": "<<a<<*s++;DD(s,k...);}pri(all)"["
,[&](){for(auto i : a)o<<i<<", ";}(),o<<"]";}using  Vi=vector<int>;pri(get<1>) "("<<a.x<<", "<<a.y<<")";}
//-----------------------------------------------------------------------------------------------------//

struct Elem {
	ll index, a, t;
	bool operator<(Elem r) const { return t < r.t; }
};

ll n, T;
vector<Elem> elems;

bool check(ll s) {
	if (s == 0) return true;
	ll time = 0, i = s;
	each(e, elems) {
		if (e.a >= s) {
			time += e.t;
			if (time > T) return false;
			if (--i == 0) return true;
		}
	}
	return false;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	cin >> n >> T;
	elems.resize(n);
	each(e, elems) cin >> e.a >> e.t;

	rep(i, 0, n) elems[i].index = i+1;
	sort(all(elems));

	ll begin = 0, end = n+1;

	while (begin+1 < end) {
		ll mid = (begin+end)/2;
		if (check(mid)) {
			begin = mid;
		} else {
			end = mid;
		}
	}

	cout << begin << endl << begin << endl;

	if (begin > 0) {
		ll time = 0, i = begin;
		each(e, elems) {
			if (e.a >= begin) {
				cout << e.index << " ";
				time += e.t;
				if (--i == 0) break;
			}
		}
	}
	cout << endl;
	return 0;
}