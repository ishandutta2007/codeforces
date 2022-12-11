#include<bits/stdc++.h>
using namespace std;
const int max_n=100+5;
int a[max_n];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			a[i]=i;
		printf("%d\n",n);
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
				printf("%d%c",a[j]," \n"[j==n]);
			if(i<n)
				swap(a[i],a[i+1]);
		}
	}
	return 0;
}