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



int32_t main() {
	int n; scanf("%d",&n);
	static int a[100<<10];
	for(int i=0;i<n;i++) scanf("%d",a+i);
	int mn=*min_element(a,a+n);
	int mx=*max_element(a,a+n);
	int Z=0;
	for(int i=0;i<n;i++) if(a[i]!=mx && a[i]!=mn) ++Z;
	printf("%d\n",Z);
}