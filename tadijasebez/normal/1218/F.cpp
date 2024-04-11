#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=100050;
int g[N],c[N];
int main(){
	int n,k,A;
	scanf("%i %i",&n,&k);
	for(int i=1;i<=n;i++)scanf("%i",&g[i]);
	scanf("%i",&A);
	for(int i=1;i<=n;i++)scanf("%i",&c[i]);
	priority_queue<int> pq;
	ll ans=0;
	for(int i=1;i<=n;i++){
		pq.push(-c[i]);
		while(k<g[i] && pq.size())k+=A,ans-=pq.top(),pq.pop();
		if(k<g[i])return 0*printf("-1\n");
	}
	printf("%lld\n",ans);
	return 0;
}