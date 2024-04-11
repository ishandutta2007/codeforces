#include<bits/stdc++.h>
using namespace std;
const int max_n=1e5+5;
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
			scanf("%d",a+i);
		while(n>0)
		{
			bool flag=false;
			for(int i=n;i>=1;--i)
			{
				if(a[i]%(i+1)!=0)
				{
					for(int j=i;j<=n-1;++j)
						a[j]=a[j+1];
					flag=true;
					break;
				}
			}
			if(flag)
				--n;
			else
				break;
		}
		puts(n?"NO":"YES");
	} 
    return 0;
}