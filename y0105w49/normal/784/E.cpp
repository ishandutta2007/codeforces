// '
#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
typedef unsigned short sint;
typedef long long ll;
typedef long double ld;
typedef complex<ld> pt;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
const ld TAU=2*acos(-1);
const ld eps=1e-8;
const int inf=1e9+99;
const ll linf=1e18+99;


int ans[]={
	0, // 0000 LOCK
	1, // 0001 LOCK
	0, // 0010 LOCK
	1, // 0011
	0, // 0100 LOCK
	0, // 0101 LOCK
	0, // 0110 LOCK
	0, // 0111
	1, // 1000 LOCK
	1, // 1001 LOCK
	0, // 1010 LOCK
	1, // 1011
	1, // 1100 LOCK
	0, // 1101 LOCK
	1, // 1110 LOCK
	1, // 1111
};


int32_t main() {
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	int x=a*8+b*4+c*2+d;
	cout<<ans[x]<<endl;
}