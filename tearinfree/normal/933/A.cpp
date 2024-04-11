#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int n,arr[2001];
int cache[2001][4];

int DP(int i,int t) {
	if(i>n) return 0;
	int &ret=cache[i][t];
	if(ret!=-1) return ret;

	ret=0;
	if(t==0 || t==2) {
		if(arr[i]==1) {
			ret = max(ret,DP(i+1,t)+1);
		}
		else {
			ret = max(ret,DP(i+1,t+1)+1);
			ret = max(ret,DP(i+1,t));
		}
	}
	else {
		if(arr[i]==1) {
			ret = max(ret,DP(i+1,t));
			if(t==1) {
				ret=max(ret,DP(i+1,t+1)+1);
			}
		}
		else {
			ret=max(ret,DP(i+1,t)+1);
		}
	}
	return ret;
}
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",arr+i);

	memset(cache,-1,sizeof(cache));
	printf("%d\n",DP(1,0));

	return 0;
}