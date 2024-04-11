#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int n;
int a[maxn];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int r=1,ans=0;
	for(int i=1;i<=n;++i)
	{
		while(r<=n&&a[i]>=a[r])r++;
		if(r>n)break;
		ans++;r++;
	}
	printf("%d\n",ans);
	return 0;
}