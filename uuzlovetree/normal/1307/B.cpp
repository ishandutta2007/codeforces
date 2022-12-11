#include<bits/stdc++.h>
using namespace std;
int T;
int n,x;
int a[100005]; 
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&x);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		int ans=1000000009;
		for(int i=1;i<=n;++i)
		{
			if(x%a[i]==0)ans=min(ans,x/a[i]);
			else ans=min(ans,max(x/a[i]-1,0)+2); 
		}
		printf("%d\n",ans);
	}
}