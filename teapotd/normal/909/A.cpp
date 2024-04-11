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

	string a, b; cin >> a >> b;

	string best = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";

	rep(i, 1, sz(a)+1) rep(j, 1, sz(b)+1) {
		string alt = a.substr(0, i) + b.substr(0, j);
		if (alt < best) best = alt;
	}

	cout << best.c_str() << endl;
	return 0;
}