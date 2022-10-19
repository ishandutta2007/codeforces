#include<bits/stdc++.h>
using namespace std;
const int N=105;
int a[N],vis[N];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(vis[i])
			continue;
		ans++;
		for(int j=i;j<=n;j++)
			if(a[j]%a[i]==0)
				vis[j]=1;	
	} 
	printf("%d\n",ans);
	return 0;
}