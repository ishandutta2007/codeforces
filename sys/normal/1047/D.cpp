#include <bits/stdc++.h>
using namespace std;
int n,m; 
int main()
{
	scanf("%d%d",&n,&m);
	if(n<=2&&m<=2){printf("0");return 0;}
	if((n==2&&m==3)||(n==3&&m==2)){printf("4");return 0;}
	if((n==2&&m==7)||(n==7&&m==2)){printf("12");return 0;}
	if(n==1)
	{
		int res=m%6;
		if(res>3) res-=2*(res-3);
		printf("%d",m-res);
		return 0;
	}
	if(m==1)
	{
		int res=n%6;
		if(res>3) res-=2*(res-3);
		printf("%d",n-res);
		return 0;
	}
	printf("%lld",(long long)n*m-((long long)n*m)%2);
	return 0;
}