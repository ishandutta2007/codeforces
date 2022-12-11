#include<bits/stdc++.h>
#define maxn 300005
using namespace std;
int n,k;
int a[maxn];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	int l=1,r=0,cnt=0;
	int ans=0;
	int ansl=1,ansr=1;
	for(l=1;l<=n;++l)
	{
		while(r<=n&&cnt<=k)
		{
			++r;
			if(!a[r])++cnt;
		}
		if(r-l>ans)
		{
			ans=r-l;
			ansl=l,ansr=r;
		}
		if(!a[l])--cnt;
	}
	printf("%d\n",ans);
	for(int i=ansl;i<ansr;++i)a[i]=1;
	for(int i=1;i<=n;++i)printf("%d ",a[i]);
	puts("");
	return 0;
}