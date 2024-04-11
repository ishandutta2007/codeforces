#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int a[N],lst[N],n,t,ans,k;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			lst[i]=0;
		}
		ans=1e9,k=1;
		for(int i=1;i<=n;i++)
		{
			if(!lst[a[i]])
				lst[a[i]]=i;
			else
			{
				if(k<=lst[a[i]])
					ans=min(ans,i-lst[a[i]]+1); 
				k=lst[a[i]]+1;
				lst[a[i]]=i;
			}
		}
		printf("%d\n",ans==1e9?-1:ans);
	}
	return 0;
}