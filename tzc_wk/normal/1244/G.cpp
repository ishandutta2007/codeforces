#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e6+5;
ll n,k;
int main(){
	scanf("%lld%lld",&n,&k);ll tot=n*(n+1)/2ll;
	if(k<tot) return puts("-1"),0;
	ll sum=0;for(ll i=1;i<=n;i++) sum+=max(i,n-i+1);
	if(sum<=k){
		printf("%lld\n",sum);
		for(int i=1;i<=n;i++) printf("%d ",i);printf("\n");
		for(int i=n;i;i--) printf("%d ",i);printf("\n");
	}
	int x=0;
	while(sum>k){
//		printf("%d %lld\n",x,sum);
		if(sum-((n-x)/2)>k){
			sum-=(n-x)/2;x++;
		} else {
			int id=(k-sum+(n-x)/2)+1;
			int forbad=n-x-id+1;
			printf("%lld\n",k);
			for(int i=1;i<=n;i++) printf("%d ",i);printf("\n");
			for(int i=n-x;i;i--) if(i!=forbad) printf("%d ",i);
			printf("%d ",forbad);for(int i=n-x+1;i<=n;i++) printf("%d ",i);
			printf("\n");return 0;
		}
	}
}
/*
6 25
*/