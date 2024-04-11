#include<bits/stdc++.h>
using namespace std;
long long a[210000];
int main(){
	int _;
	scanf("%d",&_);
	while(_--){
		int n;
		long long k;
		scanf("%d%lld",&n,&k);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		long long maxx=a[1];
		for(int i=1;i<=n;i++) maxx=max(maxx,a[i]);
		long long minn=a[1];
		for(int i=1;i<=n;i++) minn=min(minn,a[i]);
		if(k&1ll){
			for(int i=1;i<=n;i++) printf("%lld ",maxx-a[i]); 
			printf("\n");
		}
		else{
			for(int i=1;i<=n;i++) printf("%lld ",a[i]-minn); 
			printf("\n");
		}
	}
	return 0;
}