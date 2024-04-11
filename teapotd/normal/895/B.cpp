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

ll n, x, k;
vector<ll> elems;

ll check(ll i, ll j) {
	i = elems[i]; j = elems[j];
	if (i > j) return -1;

	ll a = (i - 1) / x + 1;
	ll b = j / x;
	return b - a + 1;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	cin >> n >> x >> k;
	elems.resize(n);
	each(e, elems) cin >> e;

	sort(all(elems));

	ll begin = 0, end = 0;
	ll ret = 0;

	// dbg(elems);

	rep(i, 0, n) {
		while (begin < n && check(i, begin) < k) begin++;
		while (end < n && check(i, end) <= k) end++;
		ret += end-begin;

		// dbg(i, begin, end);
	}

	cout << ret << endl;
	return 0;
}