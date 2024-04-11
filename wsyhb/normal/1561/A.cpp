#include<bits/stdc++.h>
using namespace std;
const int max_n=999+5;
int a[max_n];
inline void f(int x)
{
	if(a[x]>a[x+1])
		swap(a[x],a[x+1]);
}
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
		int ans=0;
		while(1)
		{
			bool flag_over=true;
			for(int i=1;i<=n;++i)
			{
				if(a[i]!=i)
				{
					flag_over=false;
					break;
				}
			}
			if(flag_over)
				break;
			++ans;
			int pos=ans&1?1:2;
			for(int i=pos;i<n;i+=2)
				f(i);
		}
		printf("%d\n",ans);
	}
	return 0;
}