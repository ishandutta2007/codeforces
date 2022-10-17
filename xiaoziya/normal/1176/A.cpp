#include<stdio.h>
int T;
long long n;
int main(){
	scanf("%d",&T);
	while(T--){
		int ans=0;
		scanf("%lld",&n);
		while(n%5==0)
			n/=5,ans+=3;
		while(n%3==0)
			n/=3,ans+=2;
		while(n%2==0)
			n/=2,ans+=1;
		printf("%d\n",n==1? ans:-1);
	}
	
	return 0;
}