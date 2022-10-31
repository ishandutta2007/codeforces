#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long lli;
const lli mod=1e9+7;
const int MAX = 1<<17;

int n,arr[MAX];
lli c1[MAX],c2[MAX],c3[MAX],fib[MAX];

lli v1[MAX],v2[MAX],v3[MAX];

void DFT(lli *a,int invf) {
	for(int len = 1; len < MAX; len <<= 1) {
		for(int i = 0; i < MAX; i += 2*len) {
			for(int j = 0; j < len; j++) {
				lli u = a[i + j], v = a[i + j + len];
				a[i + j] = u + v;
				a[i + j + len] = u - v;
			}
		}
	}
	if(invf) for(int i=0;i<MAX;i++) a[i] /= MAX;
}
void get(lli *des, lli *arr) {
	for(int i=0;i<MAX;i++) des[i] = arr[i] * fib[i] % mod;
	for(int i=0;i<17;i++) {
		for(int j=0;j<MAX;j++) if(!(j & (1<<i))) des[j] = (des[j] + des[j ^ (1<<i)])%mod;
	}
}
void init() {
	fib[0]=0; fib[1]=1;
	for(int i=2;i<MAX;i++) fib[i] = (fib[i-1]+fib[i-2])%mod;

	for(int i=0;i<MAX;i++) {
		int val = (MAX-1)^i;
		for(int j=val;j>=0; j = (j-1)&val) {
			c1[i | j] = (c1[i | j] + 1ll * arr[i] * arr[j])%mod;
			if(j==0) break;
		}
	}
	for(int i=0;i<MAX;i++) c3[i] = c2[i] = arr[i];
	
	DFT(c3,0);
	for(int i=0;i<MAX;i++) c3[i] *= c3[i];
	DFT(c3,1);

	for(int i=0;i<MAX;i++) {
		c1[i]%=mod; c2[i]%=mod; c3[i]%=mod;
	}
	
	get(v1,c1);
	get(v2,c2);
	get(v3,c3);
}

int pcnt[MAX<<1];
int main() {
	int val;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&val),arr[val]++;

	init();
	for(int i=0;i<MAX;i++) for(int j=0;j<17;j++) if(i>>j & 1) pcnt[i]++;
	
	lli res=0;
	for(int i=1;i<MAX;i<<=1) {
		int val=(MAX-1)^i;
		for(int j=val; j>=0; j = (j-1)&val) {
			int id = i ^ j;
			lli v=1;
			v = (v1[id]*v2[id]%mod*v3[id]%mod);
			if(pcnt[id]&1) res = (res + v)%mod;
			else res = (res - v + mod)%mod;
			
			if(j == 0) break;
		}
	}
	printf("%lld\n",res);
	
	return 0;
}