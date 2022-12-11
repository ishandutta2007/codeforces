#include <bits/stdc++.h>
#define Maxn 200007
using namespace std;
int n;
int a[Maxn],ans[Maxn],r[Maxn],t[Maxn];
bool check=true;
int main()
{
	scanf("%d",&n);
	++n;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if (i>1&&a[i]>1&&a[i-1]>1) check=false;
	}
	if (check) printf("perfect\n");
	else
	{
		printf("ambiguous\n");
		int last=0,cnt=0;
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=a[i];j++)
			{
				ans[++cnt]=last;
				r[cnt]=i;
				t[i]=cnt;
			}
			last=cnt;
		}
		for (int i=1;i<=cnt;i++)
			printf("%d ",ans[i]);
		printf("\n");
		for (int i=2;i<=n;i++)
			if (a[i]>1&&a[i-1]>1)
			{
				--ans[t[i]];
				break;
			}
		for (int i=1;i<=cnt;i++)
			printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}