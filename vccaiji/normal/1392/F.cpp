#include<bits/stdc++.h>
using namespace std;
int n;
long long h[1100000];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&h[i]);
	long long sum=0;
	for(int i=1;i<=n;i++) sum+=h[i]+i;
	if(sum%n==0){
		for(int i=1;i<=n;i++) printf("%lld ",sum/n-(n-i+1));
		return 0;
	}
	int r=n-sum%n;
	for(int i=1;i<=n-r;i++) printf("%lld ",sum/n-(n-i));
	for(int i=n-r+1;i<=n;i++) printf("%lld ",sum/n-(n-i+1));
	return 0;
}