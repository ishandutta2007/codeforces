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

ll nElems, mod;
vector<ll> elems, mods;

ll phi(ll n) {
	ll ret = n;
	for (ll p = 2; p*p <= n; p++) {
		if ((n % p) == 0) {
			while ((n % p) == 0) n /= p;
			ret -= ret / p;
		}
	}
	return (n > 1 ? ret - ret/n : ret);
}

ll modPow(ll base, ll exp, ll m) {
	ll ret = 1;
	base %= m;

	while (exp > 0) {
		if (exp & 1) ret = (ret*base) % m;
		base = (base*base) % m;
		exp >>= 1;
	}
	return ret % m;
}

ll tower(int begin, int end, int mi) {
	if (begin >= end || mi >= sz(mods)-1) return 1;
	ll naive = 1;
	bool usePhi = false;

	int i = begin;
	while (i < end-1 && i < begin+5 && elems[i] != 1) i++;

	for (; i > begin; i--) {
		ll times = naive;
		naive = 1;

		if (elems[i] > 1) {
			rep(j, 0, times) {
				naive *= elems[i];
				if (naive >= 32) {
					usePhi = true;
					goto outLoop;
				}
			}
		}
	}
	outLoop:;

	if (!usePhi) return modPow(elems[begin], naive, mods[mi]);

	ll p = tower(begin+1, end, mi+1);
	return modPow(elems[begin], mods[mi+1] + (p % mods[mi+1]), mods[mi]);
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	cin >> nElems >> mod;
	for (ll m = mod; m > 1; m = phi(m)) mods.push_back(m);
	mods.push_back(1);
	mods.push_back(1);

	elems.resize(nElems);
	each(e, elems) cin >> e;

	int q; cin >> q;

	while (q--) {
		int begin, end; cin >> begin >> end;
		cout << tower(begin-1, end, 0) << endl;
	}

	return 0;
}