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

using ld = long double;

int n;
ld r;
vector<ld> cordX, cordY;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	cin >> n >> r;
	cordX.resize(n);
	cordY.resize(n);
	each(e, cordX) cin >> e;

	rep(i, 0, n) {
		ld x = cordX[i], y = r;

		rep(j, 0, i) {
			ld dx = abs(cordX[j] - x);
			ld dr = 2*r;
			if (dx-1e-7 <= dr) {
				ld a = sqrt(dr*dr - dx*dx);
				y = max(y, cordY[j]+a);
			}
		}

		cordY[i] = y;
		cout << y << " ";
	}
	cout << endl;
	return 0;
}