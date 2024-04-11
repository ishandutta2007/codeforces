#pragma GCC optimize("Ofast,no-stack-protector")
#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
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

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n; cin >> n;

	vector<bool> nonZero(10, false);
	vector<ll> counts(10);

	rep(i, 0, n) {
		ll mult = 1;
		string s; cin >> s;
		nonZero[s[0]-'a'] = true;

		repd(j, sz(s)-1, 0) {
			counts[s[j]-'a'] += mult;
			mult *= 10;
		}
	}

	ll best = -1;
	int bestI = 0;

	rep(i, 0, sz(nonZero)) if (!nonZero[i] && best < counts[i]) {
		best = counts[i];
		bestI = i;
	}

	counts.erase(counts.begin()+bestI);
	sort(all(counts), [](ll l, ll r) { return l > r; });

	ll ret = 0;
	rep(i, 0, sz(counts)) ret += counts[i]*(i+1);

	cout << ret << endl;
	return 0;
}