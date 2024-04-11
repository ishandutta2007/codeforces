#include<bits/stdc++.h>
using namespace std;
int T,a,b;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&a,&b);
		int x=0;
		for(int i=30;i>=0;--i)if((a&(1<<i))&&(b&(1<<i)))x|=(1<<i);
		printf("%d\n",(a^x)+(b^x));
	}
}