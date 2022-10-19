#include<bits/stdc++.h>
using namespace std;
const int N=2005;
int a[N],n,t;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int f1=0,f2=0,sum=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]&1)
				f1=1;
			else
				f2=1;
			sum+=a[i];
		}
		if(sum%2==1||(f1&&f2))
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}