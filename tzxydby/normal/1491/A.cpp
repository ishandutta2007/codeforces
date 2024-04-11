#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,q,a[N],s1;
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i])
			s1++;
	}
	while(q--)
	{
		int t,x;
		scanf("%d%d",&t,&x);
		if(t==1)
		{
			if(a[x])
			{
				a[x]=0;
				s1--;
			}
			else
			{
				a[x]=1;
				s1++;
			}
		}
		else
		{
			if(s1>=x)
				puts("1");
			else
				puts("0");
		}
	}
	return 0;
}