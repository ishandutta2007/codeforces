#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a,b,k,h[200005],ans;
int main()
{
	scanf("%d%d%d%d",&n,&a,&b,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&h[i]);
		h[i]--;
		h[i]%=a+b;
		if(h[i]<a)ans++,h[i]=2000000000;
		else h[i]=h[i]/a;
	}
	sort(h+1,h+n+1);
	for(int i=1;i<=n;i++)
	{
		if(k>=h[i])
		{
			k-=h[i];
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}