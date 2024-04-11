#include <cstdio>
#include <algorithm>
#include <queue>
#include <functional>

typedef long long lli;
int n;
lli s,arr[100001];

lli Check(int k) {
	std::priority_queue<lli,std::vector<lli>,std::greater<lli>> que;
	for(int i=1;i<=n;i++) {
		que.push(arr[i]+(long long)i*k);
	}
	lli res=0;
	while(k--) {
		res+=que.top();que.pop();
		if(res>s) return -1;
	}
	return res;
}

int main() {
	scanf("%d %lld",&n,&s);
	for(int i=1;i<=n;i++) scanf("%lld",arr+i);
	
	int lo=0,up=n+1;
	lli res=0;
	while(up-lo>1) {
		int md=(lo+up)/2;
		lli tmp=Check(md);
		if(tmp==-1) up=md;
		else {
			lo=md;
			res=tmp;
		}
	}
	printf("%d %lld\n",lo,res);
	
	return 0;
}