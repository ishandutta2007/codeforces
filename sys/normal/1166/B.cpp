#include <bits/stdc++.h>
using namespace std;
int k,n,m;
string str;
char ch[]={'a','e','i','o','u'};
int main()
{
	scanf("%d",&k);
	for(int i=5;i<=k;i++)
		if(k%i==0&&k/i>=5)
			{
				n=i;
				break;
			}
	if(!n)
	{
		printf("-1");
		return 0;
	}
	if(n!=5)
		for(int i=0;i<k;i++)
			printf("%c",ch[i%5]);
	else
	{
		int tmp=0;
		for(int i=0;i<5;i++)
		{
			tmp++;
			for(int j=0;j<k/5;j++)
				printf("%c",ch[(tmp+j)%5]);
		}
	}
	return 0;
}