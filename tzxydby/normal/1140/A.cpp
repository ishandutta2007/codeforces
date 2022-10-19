#include<bits/stdc++.h>
using namespace std;
const int N=10005;
int a[N];
int main()
{
	int n,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		int nmax=a[i];
		ans++;
		while(i<=n&&i<nmax)
		{
			i++;
			nmax=max(nmax,a[i]);
		}
	}
	printf("%d\n",ans);
	return 0;
}