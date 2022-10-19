#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int t,n,a[N],id[N];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),id[i]=i;
		if(a[1]==a[2])
		{
			int fl=0;
			for(int i=3;i<=n;i++)
			{
				if(a[i]!=a[1])
				{
					fl=1;
					swap(a[2],a[i]);
					swap(id[2],id[i]);
					break;
				}
			}
			if(!fl)
			{
				puts("NO");
				continue;
			}
		}
		puts("YES");
		printf("%d %d\n",id[1],id[2]);
		for(int i=3;i<=n;i++)
		{
			if(a[i]==a[1])
				printf("%d %d\n",id[2],id[i]);
			else
				printf("%d %d\n",id[1],id[i]);
		}
	}
	return 0;
}