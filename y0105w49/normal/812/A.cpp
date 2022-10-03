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













int32_t main() {
	static bool car[4],ped[4];
	for(int i=0;i<4;i++) {
		int l,s,r,p; cin>>l>>s>>r>>p;
		if(l||s||r) car[i]=1;
		car[(i+3)%4]|=l;
		car[(i+2)%4]|=s;
		car[(i+1)%4]|=r;
		ped[i]=p;
	}
	for(int i=0;i<4;i++) if(ped[i] && car[i]) {
		cout<<"YES\n";
		return 0;
	}
	cout<<"NO\n";
}