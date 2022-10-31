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

int n,m,cache[1<<22],bit[22];

int DP(int s) {
	if(s==(1<<n)-1) return 0;
	
	int &ret=cache[s];
	if(ret!=-1) return ret;

	ret=n+1;
	for(int i=0;i<n;i++) if(s&(1<<i)) {
		int nxt=s|bit[i];
		if(nxt==s) continue;
		
		ret=min(ret,DP(nxt)+1);
	}
	return ret;
}
void trace(int s) {
	if(s==(1<<n)-1) return ;
	
	int &ret=cache[s];
	
	for(int i=0;i<n;i++) if(s&(1<<i)) {
		int nxt=s|bit[i];
		if(nxt==s) continue;

		if(DP(nxt)==ret-1) {
			printf("%d ",i+1);
			trace(nxt);
			return;
		}
	}
}
int main() {
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		a--; b--;
		bit[a]|=1<<b;
		bit[b]|=1<<a;
	}
	for(int i=0;i<n;i++) bit[i]|=1<<i;

	int flag=1;
	for(int i=0;i<n;i++) {
		if(bit[i]!=(1<<n)-1) flag=false;
	}
	if(flag) {
		puts("0");
		return 0;
	}
	memset(cache,-1,sizeof(cache));
	
	int mx=n+1,id=0;
	for(int i=0;i<n;i++) {
		if(mx>DP(bit[i])) {
			mx=DP(bit[i]);
			id=i;
		}
	}
	printf("%d\n",mx+1);
	printf("%d ",id+1);
	trace(bit[id]);
	
	return 0;
}