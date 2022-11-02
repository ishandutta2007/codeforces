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
#ifdef LOCx
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

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n; cin >> n;
	vector<ll> dists(n);
	vector<char> colors(n);

	rep(i, 0, n) {
		cin >> dists[i] >> colors[i];
	}

	ll ret = 0;
	ll lastR = INT_MAX, lastG = -1, lastB = INT_MAX;
	ll gapR = 0, gapB = 0;

	rep(i, 0, n) {
		if (colors[i] == 'R') {
			ret += max(dists[i]-lastR, 0ll);
			gapR = max(dists[i]-lastR, gapR);
			lastR = dists[i];
		} else if (colors[i] == 'B') {
			ret += max(dists[i]-lastB, 0ll);
			gapB = max(dists[i]-lastB, gapB);
			lastB = dists[i];
		} else if (colors[i] == 'G') {
			ret += max(dists[i]-lastR, 0ll);
			ret += max(dists[i]-lastB, 0ll);
			gapR = max(dists[i]-lastR, gapR);
			gapB = max(dists[i]-lastB, gapB);

			if (lastG >= 0) {
				ll delta = dists[i]-lastG - gapR - gapB;
				if (delta < 0 || gapR == 0 || gapB == 0) {
					ret += delta;
				}
			}

			gapR = gapB = 0;
			lastR = lastG = lastB = dists[i];
		}

		deb(ret);
	}

	cout << ret << endl;
	return 0;
}