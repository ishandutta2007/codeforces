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








int n,S;
int a[100<<10];
ll w[100<<10];

ll co(int k) {
	for(int i=0;i<n;i++) w[i]=a[i]+1LL*(i+1)*k;
	sort(w,w+n);
	ll Z=accumulate(w,w+k,0LL);
	return Z>S ? -1 : Z;
}


int32_t main() {
	scanf("%d%d",&n,&S);
	for(int i=0;i<n;i++) scanf("%d",a+i);
	int L=0,R=n;
	for(;L<R;) {
		int M=(L+R+1)>>1;
		if(co(M)!=-1) L=M;
		else R=M-1;
	}
	cout<<L<<" "<<co(L)<<endl;
}