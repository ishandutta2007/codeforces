#include<bits/stdc++.h>
using namespace std;
long long n,k;
int main(){
	scanf("%I64d%I64d",&n,&k);
	if (k>=2){
		long long ans=0;
		for (;n;n/=2,ans=ans*2+1);
		printf("%I64d",ans);
	}
	else printf("%I64d",n);
}