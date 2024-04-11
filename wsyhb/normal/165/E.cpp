#include<bits/stdc++.h>
using namespace std;
const int max_n=1e6+5;
int a[max_n];
const int max_R=1<<22|5;
int id[max_R];
int main()
{
	int n;
	scanf("%d",&n);
	int mx=0;
	for(int i=1;i<=n;++i)
	{
		scanf("%d",a+i);
		id[a[i]]=a[i];
		mx=max(mx,a[i]);
	}
	int R=1,k=0;
	while(R<=mx)
		R<<=1,++k;
	for(int S=0;S<=R-1;++S)
	{
		if(!id[S])
			continue;
		for(int i=0;i<k;++i)
		{
			if(~S>>i&1)
				id[S|(1<<i)]=id[S];
		}
	}
	for(int i=1;i<=n;++i)
	{
		int ans=id[a[i]^(R-1)];
		if(!ans)
			ans=-1;
		printf("%d%c",ans,i<n?' ':'\n');
	}
	return 0;
}