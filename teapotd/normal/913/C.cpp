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

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	ll n, L; cin >> n >> L;

	vector<ll> opts(n);
	each(x, opts) cin >> x;
	opts.resize(31, numeric_limits<ll>::max());

	rep(i, 1, 31) if (2*opts[i-1] < opts[i]) opts[i] = 2*opts[i-1];

	vector<ll> dyn(32);
	dyn[0] = 0;

	rep(i, 1, 32) {
		if (L & 1) {
			dyn[i] = dyn[i-1] + opts[i-1];
		} else {
			dyn[i] = min(dyn[i-1], opts[i-1]);
		}
		L >>= 1;
	}

	cout << dyn.back() << endl;
	return 0;
}