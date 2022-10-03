#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex<ld> pt;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
const ld TAU=2*acos(-1);
const ld eps=1e-7;
const int inf=1e9+99;
const ll linf=1e18+88;



const int N=100<<10;
int a[N];
ll p[N];

int32_t main() {
	int n,k; scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++) scanf("%d",a+i);
	p[0]=0;
	for(int i=0;i<n;i++) p[i+1]=p[i]+a[i];

	ll x=1;
	ll Z=0;
	for(;;) {
		map<ll,int> ct;
		for(int i=0;i<n;i++) {
			ct[p[i]]++;
			Z+=ct[p[i+1]-x];
		}

		x*=k;
		if(x>ll(1e15)) break;
		if(x==1) break;
	}
	cout<<Z<<endl;
}