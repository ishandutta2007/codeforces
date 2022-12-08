#include<bits/stdc++.h>
#define N 200010
using namespace std;
map<int,int>use;
int n,i,a[N],ans,l,r,b[N];
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]),ans=max(ans,a[i]);
	for(l=n,r=ans;l<r;)
	{
		int mid=l+r>>1;
		use.clear();
		for(i=1;i<=n;i++)b[i]=a[i],use[a[i]]=1;
		sort(b+1,b+n+1);
		for(i=n;i>=1;i--)
		{
			use[b[i]]=0;
			for(;b[i]>mid;b[i]>>=1);
			for(;use[b[i]]&&b[i]>1;b[i]>>=1);
			if(use[b[i]])break;
			use[b[i]]=1;
		}
		if(i>=1)l=mid+1;else r=mid;
	}
	use.clear();
	for(i=1;i<=n;i++)b[i]=a[i],use[a[i]]=1;
	sort(b+1,b+n+1);
	for(i=n;i>=1;i--)
	{
		use[b[i]]=0;
		for(;b[i]>l;b[i]>>=1);
		for(;use[b[i]]&&b[i]>1;b[i]>>=1);
		if(use[b[i]])break;
		use[b[i]]=1;
	}
	for(i=1;i<=n;i++)printf("%d ",b[i]);
}