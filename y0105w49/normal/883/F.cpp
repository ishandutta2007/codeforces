// ayy
// ' lamo
#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld; //CARE
typedef complex<ld> pt;
#define fi first
#define se second
#define pb push_back
const ld eps=1e-8;
const int inf=1e9+99;
const ll linf=1e18+99;
const int P=1e9+7;







set<string> ss;


string reduce(string s) {
	string t="";
	for(char c:s) {
		if(c=='h') for(;t.size() && t.back()=='k';) t.pop_back();
		if(c=='u') { t+="oo"; continue; }
		t+=c;
	}
	return t;
}





int32_t main() {
	int n; cin>>n;
	for(string s;n--;) cin>>s, ss.insert(reduce(s));
	cout<<ss.size()<<endl;
}