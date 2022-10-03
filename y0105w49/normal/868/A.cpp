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






void win() {
	cout<<"YES"<<endl;
	exit(0);
}






int32_t main() {
	string S; cin>>S;
	int n; cin>>n;
	vector<string> vv;
	for(int i=0;i<n;i++) {
		string s; cin>>s; vv.pb(s);
	}
	for(string s:vv) if(s==S) win();
	for(int i=0;i<n;i++) for(int j=0;j<n;j++)
		if(vv[i][0]==S[1] && vv[j][1]==S[0]) win();
	cout<<"NO"<<endl;
}