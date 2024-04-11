#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c,d;
	scanf("%d:%d",&a,&b);
	scanf("%d:%d",&c,&d);
	int tim=c*60+d-a*60-b;
	tim/=2;
	b+=tim;
	a+=b/60;
	b%=60;
	if(a<10)
	{
		printf("0%d:",a);
	}
	else
	{
		printf("%d:",a);
	}
	if(b<10)
	{
		printf("0%d",b);
	}
	else
	{
		printf("%d",b);
	}
	return 0;
}