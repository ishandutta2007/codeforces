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

constexpr ll INF = ll(1e18)+1;

ll n, k;
vector<ll> allPrimes, primes1, primes2, opts1, opts2;

inline ll safeMult(ll a, ll b) {
	constexpr ll OVER = 1ll << 31;
	if (a >= OVER && b >= OVER) return INF;
	if (((a >> 31)*b + (b >> 31)*a) >= OVER) return INF;
	return a*b;
}

void genOpts(vector<ll>& divs, vector<ll>& out, ll p = 1, ll i = 0) {
	if (i == sz(divs)) {
		out.pb(p);
		return;
	}

	while (p < INF) {
		genOpts(divs, out, p, i+1);
		p = safeMult(p, divs[i]);
	}
}

ll smaller(ll x) {
	int j = sz(opts2)-1;
	ll ret = 0;

	each(part, opts1) {
		while (j >= 0 && safeMult(opts2[j], part) > x) j--;
		if (j < 0) break;
		ret += j+1;
	}
	return ret;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	cin >> n;
	allPrimes.resize(n);
	each(p, allPrimes) cin >> p;
	cin >> k;

	// Partition

	each(p, allPrimes) {
		if (p == 2 || p == 3 || p == 5 || p == 7 || p == 11 || p == 13) {
			primes1.pb(p);
		} else {
			primes2.pb(p);
		}
	}

	// Compute partial

	genOpts(primes1, opts1);
	genOpts(primes2, opts2);

	deb(sz(opts1)/1000000.0, sz(opts2)/1000000.0);

	sort(all(opts1));
	sort(all(opts2));

	ll begin = 1, end = INF;
	while (begin+1 < end) {
		ll mid = (begin+end)/2-1;
		ll c = smaller(mid);

		if (c < k) {
			begin = mid+1;
		} else {
			end = mid+1;
		}
	}

	for (ll i = begin-1; i <= end+1; i++) {
		if (smaller(i) == k) {
			cout << i << endl;
			return 0;
		}
	}
	return 0;
}