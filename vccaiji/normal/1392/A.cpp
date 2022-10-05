#include<bits/stdc++.h>
using namespace std;
long long a[210000];
int main(){
	int _;
	scanf("%d",&_);
	while(_--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		bool r=0;
		for(int i=1;i<n;i++)if(a[i]!=a[i+1])r=1;
		if(r) printf("1\n");
		else printf("%d\n",n);
	}
	return 0;
}