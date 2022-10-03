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
	const int N=1024;
	int n,k,x; scanf("%d%d%d",&n,&k,&x);
	static int c1[N],c2[N];
	for(;n--;) {
		int a; scanf("%d",&a); ++c1[a];
	}
	for(;k--;) {
		bool flip_next=1;
		for(int i=0;i<N;i++) {
			c2[i] += c1[i]>>1;
			c2[i^x] += c1[i]>>1;
			if(c1[i]&1) {
				if(flip_next) c2[i^x]++;
				else c2[i]++;
				flip_next = !flip_next;
			}
		}
		for(int i=0;i<N;i++) c1[i]=c2[i], c2[i]=0;
	}
	int mn=N+7,mx=-1;
	for(int i=0;i<N;i++) if(c1[i]) mx=i;
	for(int i=N;--i>=0;) if(c1[i]) mn=i;
	printf("%d %d\n",mx,mn);
}