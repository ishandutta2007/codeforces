#include<bits/stdc++.h>
using namespace std;
int a,b;
int main()
{
	scanf("%d%d",&a,&b);
	int aa=0,p=0,bb=0;
	for(int i=1;i<=6;i++)
	{
		if(abs(a-i)<abs(b-i))
		{
			aa++;
		}
		if(abs(a-i)==abs(b-i))
		{
			p++;
		}
		if(abs(a-i)>abs(b-i))
		{
			bb++;
		}
	}
	printf("%d %d %d",aa,p,bb);
	return 0;
}