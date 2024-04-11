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
	int n,k; scanf("%d%d",&n,&k);
	set<int> ss;
	for(int i=0;i<n;i++) {
		int mk=0;
		for(int j=0;j<k;j++) {
			int x; scanf("%d",&x);
			mk=mk*2+x;
		}
		ss.insert(mk);
	}
	for(int x:ss) for(int y:ss) {
		if(!(x&y)) return cout<<"YES"<<endl,0;
	}
	cout<<"NO"<<endl;
}