#include <bits/stdc++.h>
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define rep(i,b,e)for(int i=(b);i<(e);i++)
#define repd(i,b,e)for(int i=(b);i>=(e);i--)
#define each(a,x)for(auto&a:(x))
#define all(x)(x).begin(),(x).end()
#define sz(x)int((x).size())
#define tem template<class t,class...g>
#define D DD()
#define pri(k)tem auto p(t a,ll)->decltype(a.k,z()){D
#define DBP(...)void print(){D.x("{"#__VA_ARGS__,__VA_ARGS__);D,"}";}
#ifdef LOC
#define deb(...)((D,"<",__LINE__,"> ").x(#__VA_ARGS__,__VA_ARGS__),D,"\n")
#else
#define deb(...)
#endif
using namespace std;using namespace rel_ops;using ll=long long;using Vi=vector<int>;
using Pii=pair<int,int>;struct DD{using z=void;z x(...){}tem z p(t a,...){cerr<<a;}
tem DD&operator,(t a){p(a,0);return*this;}pri(first),"(",a.first,", ",a.second,")";}
tem z x(const char*s,t a,g...k){while(*s&&*s!=',')D,*s++;D,": ",a,*s++;x(s,k...);}
pri(print());a.print();}pri(begin()),"[";each(k,a)D,k,", ";D,"]";}};

// ------------------------------------------------------------------------------------------ //

constexpr ll MOD = 1e9+7;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n; cin >> n;
	vector<ll> prev(n+1), cur(n+1);
	cur[0] = 1;

	rep(i, 0, n) {
		char chr; cin >> chr;
		cur.swap(prev);

		if (chr == 'f') {
			cur[0] = 0;
			rep(j, 1, n+1) cur[j] = prev[j-1];
		} else {
			ll sum = 0;
			repd(j, n, 0) {
				sum += prev[j];
				cur[j] = sum % MOD;
			}
		}
	}

	ll ret = 0;
	each(x, prev) ret += x;

	cout << ret % MOD << endl;
	return 0;
}