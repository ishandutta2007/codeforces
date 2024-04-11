#include<bits/stdc++.h>
using namespace std;
const int max_n=2e5+5;
int a[max_n],b[max_n];
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
		int cnt=0;
		for(int i=1;i<=n-1;++i)
		{
			b[i]=(a[i]==a[i+1]);
			cnt+=b[i];
		}
		if(cnt<=1)
		{
			puts("0");
			continue;
		}
		int L=-1,R=-1;
		for(int i=1;i<=n-1;++i)
		{
			if(b[i])
			{
				L=i;
				break;
			}
		}
		for(int i=n-1;i>=1;--i)
		{
			if(b[i])
			{
				R=i;
				break;
			}
		}
		if(L+1==R)
		{
			puts("1");
			continue;
		}
		printf("%d\n",R-L-1);
	}
	return 0;
}