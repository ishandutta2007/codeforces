#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int a[N];
int main()
{
	int n,x,y;
	scanf("%d%d%d",&n,&x,&y);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		int flag=1;
		for(int j=max(1,i-x);j<i;j++)
			if(a[j]<a[i])
				flag=0;
		for(int j=i+1;j<=min(i+y,n);j++)
			if(a[j]<a[i])
				flag=0;
		if(flag)
		{
			printf("%d\n",i);
			break;
		}
	}
	return 0;
}