#include <bits/stdc++.h>
using namespace std;
typedef long long lli;

int n;
lli arr[200001],sum[200001];

int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",arr+i);

	priority_queue<lli,vector<lli>,greater<lli>> que;
	for(int i=1;i<=n;i++) que.push(arr[i]);

	lli ans=0;
	if(n%2==0) {
		lli v=que.top(); que.pop();
		v+=que.top(); que.pop();
		que.push(v);
		ans+=v;
	}

	while(que.size()>1) {
		lli v1,v2,v3;
		v1=que.top(); que.pop(); v2=que.top(); que.pop();
		v3=que.top(); que.pop(); que.push(v1+v2+v3);
		ans+=v1+v2+v3;
	}
	printf("%lld\n",ans);

	return 0;
}