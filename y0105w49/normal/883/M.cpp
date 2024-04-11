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
	int x,y; cin>>x>>y;
	int _x,_y; cin>>_x>>_y;
	x-=_x, y-=_y;

	int Z=2*(abs(x)+abs(y)+2);
	if(!x || !y) Z+=2;
	cout<<Z<<endl;
}