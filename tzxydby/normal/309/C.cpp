#include<bits/stdc++.h>
using namespace std;
int a[40],b[40];
int main()
{
	int n,m,x,sum=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		int k=0;
		while(x)
		{
			a[k++]+=x&1;
			x/=2;
		}
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&x);
		b[x]++;
	}
	while(1)
	{
		int i=0;
		while(i<32&&!b[i])
			i++;
		if(i==32)
			break;
		b[i]--;
		while(i<32&&!a[i])
		{
			a[i]++;
			i++;
		}
		if(i==32)
			break;
		a[i]--;
		sum++;
	}
	printf("%d\n",sum);
	return 0;
}