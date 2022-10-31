#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <map>
#include <cstring>

using namespace std;
typedef long long lli;

const lli inf=20000;

int n;
lli cache[30][11];
lli DP(int idx,int val) {
	if(val<0) return 0;
	if(idx==-1) return val==0;

	lli &ret=cache[idx][val];
	if(ret!=-1) return ret;

	ret=0;
	for(int i=0;i<10;i++) {
		ret=min(inf,ret+DP(idx-1,val-i));
	}
	return ret;
}
void trace(int idx,int val,int f,int k) {
	if(idx==-1) return;
	for(int i=0;i<10;i++) {
		if(DP(idx-1,val-i) >= k) {
			if(i || f) printf("%d",i);
			trace(idx-1,val-i, i>0 || f, k);
			return;
		}
		k-=DP(idx-1,val-i);
	}
}

int main() {
	scanf("%d",&n);
	memset(cache,-1,sizeof(cache));
	DP(29,10);
	trace(29,10,0,n);

	return 0;
}