#include <bits/stdc++.h>
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define rep(i,b,e)for(int i=(b);i<(e);i++)
#define repd(i,b,e)for(int i=(b);i>=(e);i--)
#define each(a,x)for(auto&a:(x))
#define all(x)(x).begin(),(x).end()
#define sz(x)int((x).size())
#define TM template<class T,class U=int,class...V>
#define DF(t,...)TM auto operator<<(ostream&o,__VA_ARGS__ x)->decltype(t,cout)
#define DD(...)void print(){cerr<<'{';debx(#__VA_ARGS__,__VA_ARGS__);cerr<<'}';}
#ifdef LOC
#define deb(...)(cerr<<"<"<<__LINE__,debx("> "#__VA_ARGS__,__VA_ARGS__),cerr<<"\n")
#else
#define deb(...)
#endif
using namespace std;using namespace rel_ops;using ll=int64_t;using Vi=vector<int>;using Pii=pair<int,int>;
void debx(...){}TM void debx(T s,U a,V...b){while(*s&&*s!=',')cerr<<*s++;cerr<<": "<<a<<*s++;debx(s,b...);}
DF(&T::print,T){x.print();return o;}DF(0,pair<T,U>){return o<<"("<<x.first<<", "<<x.second<<")";}
DF(T().begin(),T){o<<"[";each(e,x)o<<e<<", ";return o<<"]";}

// ----------------------------------------------------------------------------------------------------- //

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n; cin >> n;

	vector<int> layers;

	rep(begin, 0, n) {
		rep(end, begin+1, n+1) {
			bool ok = false;
			each(l, layers) if (l <= begin) {
				l = end;
				ok = true;
				break;
			}
			if (!ok) layers.pb(end);
		}
	}

	cout << sz(layers) << endl;
	return 0;
}