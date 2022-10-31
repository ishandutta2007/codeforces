#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <complex>
#include <cmath>
#include <cstring>
#include <map>

using namespace std;
typedef long long lli;
typedef pair<lli, lli> pll;
typedef pair<int, int> pii;
const lli mod=1e9+7;
const int inf=1e9;

int n,a[100];
int prime[17]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59};
int cache[1<<17][100];

int pf[61];

inline int _abs(int a) {
	return a<0 ? -a : a;
}
int DP(int s,int idx) {
	if(idx==n) return 0;

	int &ret=cache[s][idx];
	if(ret!=-1) return ret;
	
	ret=10000;
	for(int i=1;i<60;i++) {
		int nx=pf[i];
		if( (s&nx)==0 ) ret=min(ret,DP(s|nx,idx+1)+_abs(a[idx]-i));
	}
	return ret;
}
void trace(int s,int idx) {
	if(idx==n) return ;

	int &ret=cache[s][idx];

	for(int i=1;i<60;i++) {
		int nx=pf[i];
		if( (s&nx)==0 && DP(s|nx,idx+1)+_abs(a[idx]-i)==ret) {
			printf("%d ",i);
			trace(s|nx,idx+1);
			return;
		}
	}
}
int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",a+i);
	
	for(int i=1;i<60;i++) {
		int val=i,nx=0;
		for(int j=0;j<17 && val!=1;j++) {
			if(val%prime[j]==0) {
				while(val%prime[j]==0) val/=prime[j];
				nx|=1<<j;
			}
		}
		pf[i]=nx;
	}

	memset(cache,-1,sizeof(cache));
	DP(0,0);
	trace(0,0);

	return 0;
}