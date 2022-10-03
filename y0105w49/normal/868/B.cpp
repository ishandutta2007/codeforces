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
	int h,m,s,t1,t2; cin>>h>>m>>s>>t1>>t2;
	ld H=h+ld(m)/60 + ld(s)/3600;
	ld M=(m+ld(s)/60)*12/60;
	ld S=ld(s)*12/60;

	vector<ld> ss={(ld)t1,(ld)t2,H,M,S};
	sort(ss.begin(),ss.end());
	ss.pb(ss[0]);
	for(int i=0;i<5;i++) {
		if(ss[i]==t1 && ss[i+1]==t2) win();
		if(ss[i+1]==t1 && ss[i]==t2) win();
	}
	cout<<"NO"<<endl;
}