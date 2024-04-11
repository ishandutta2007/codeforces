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






#define dec aresti
const int N=1<<20;
int n,k,v[N],inc[N],dec[N];



int32_t main() {
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++) scanf("%d",v+i);
	sort(v,v+n);
	int L=0,R=v[n-1]-v[0];
	for(;L!=R;) {
		int M=(L+R)/2;
		for(int i=0;i<=n;i++) inc[i]=dec[i]=0;
		inc[0]=dec[0]=1;
		int h=0;
		int j=0;
		for(int i=0;i<=n;i++) {
			h+=inc[i];
			assert(h>=0);
			if(i==n) break;
			if(!h) goto gg;
			if(i+k>n) goto gg;
			if(v[i+k-1]-v[i] > M) goto gg;
			inc[i+k]++;

			j=max(j,i+k);
			for(;v[j]-v[i]<=M;) ++j;
			dec[j]++;

			gg:;
			h-=dec[i];
			assert(h>=0);
		}
		if(h) R=M;
		else L=M+1;
	}
	printf("%d\n",L);
}