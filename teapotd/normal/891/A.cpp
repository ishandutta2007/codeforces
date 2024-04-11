#pragma GCC optimize("Ofast,no-stack-protector")
#include <bits/stdc++.h>

#define mp make_pair
#define rep(i,b,e)for(int i=(b);i<(e);i++)
#define repd(i,b,e)for(int i=(b);i>=(e);i--)
#define each(a,x)for(auto&a:(x))
#define all(x)(x).begin(),(x).end()
#define sz(x)int((x).size())
#define TM template<class T,class U=int,class...V>
#define DF(t,...)TM auto operator<<(ostream&o,__VA_ARGS__ x)->decltype(t,cout)
#define DD(...)void print(){cerr<<'{';dbgx(#__VA_ARGS__,__VA_ARGS__);cerr<<'}';}
#ifdef LOC
#define dbg(...)(cerr<<"<"<<__LINE__,dbgx("> "#__VA_ARGS__,__VA_ARGS__),cerr<<"\n")
#else
#define dbg(...)
#endif
using namespace std;using namespace rel_ops;using ll=int64_t;using Vi=vector<int>;using Pii=pair<int,int>;
void dbgx(...){}TM void dbgx(T s,U a,V...b){while(*s&&*s!=',')cerr<<*s++;cerr<<": "<<a<<*s++;dbgx(s,b...);}
DF(&T::print,T){x.print();return o;}DF(0,pair<T,U>){return o<<"("<<x.first<<", "<<x.second<<")";}
DF(T().begin(),T){o<<"[";each(e,x)o<<e<<", ";return o<<"]";}

// ----------------------------------------------------------------------------------------------------- //

ll gcd(ll a, ll b) {
	if (a < b) swap(a, b);

	while (b != 0) {
		ll c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	ll n, ones = 0; cin >> n;
	vector<ll> elems(n);

	each(e, elems) {
		cin >> e;
		if (e == 1) ones++;
	}

	if (ones > 0) {
		cout << n-ones << endl;
		return 0;
	}

	ll best = n+5;

	rep(i, 0, n) {
		ll g = elems[i];

		rep(j, i, n) {
			g = gcd(g, elems[j]);
			if (g == 1) {
				best = min(best, ll(j-i));
				break;
			}
		}
	}

	if (best > n) {
		cout << "-1\n";
		return 0;
	}

	cout << n+best-1 << endl;
	return 0;
}