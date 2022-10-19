#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,k,a[N],c[N],ans;
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++) 
		scanf("%d",&a[i]);
	for(int i=1;i<=k;i++) 
		scanf("%d",&c[i]);
	sort(a,a+n,greater<int>());
	for(int i=0;i<n;i++)
		ans=max(ans,(int)ceil(1.0*(i+1)/c[a[i]]));
	printf("%d\n",ans);
	for(int i=0;i<ans;i++)
	{
		printf("%d ",n/ans+(i<n%ans));
		for(int j=i;j<n;j+=ans) 
			printf("%d ",a[j]);
		puts("");
	}
	return 0;
}