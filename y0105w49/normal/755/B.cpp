#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef complex<ld> pt;
typedef long long ll;
#define fi first
#define se second
#define pb push_back








bool _main() {
	int n,m; cin>>n>>m;
	set<string> P,E,B;
	string s;
	for(;n--;) cin>>s, P.insert(s);
	for(;m--;) cin>>s, E.insert(s);
	for(const string &s:P) if(E.count(s)) B.insert(s);

	int p=(int)P.size();
	int e=(int)E.size();
	int b=(int)B.size();
	p-=b;
	e-=b;

	if(b&1) return (p>=e);
	return p>e;
}
int main() {
	cout<<(_main() ? "YES" : "NO")<<endl;
}