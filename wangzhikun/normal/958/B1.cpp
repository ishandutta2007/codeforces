#include<cstdio>
using namespace std;
int n,a[1005],x,y,ans=0;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		a[x]++;
		a[y]++;
	}
	for(int i=1;i<=n;i++)if(a[i]==1)ans++;
	printf("%d",ans);
	return 0; 
}