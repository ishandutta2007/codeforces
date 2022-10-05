#include <bits/stdc++.h>
using namespace std;
const int Maxn=1000005;
int n,w,l[Maxn];
vector <int> Ve[Maxn];
long long ans[Maxn],ans2[Maxn];
int Qu[Maxn];
int main()
{
//	freopen("E.in","r",stdin); 
	scanf("%d%d",&n,&w);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&l[i]);
		Ve[i].push_back(0);
		for(int j=1;j<=l[i];j++)
		{
			int x;
			scanf("%d",&x);
			Ve[i].push_back(x);
		}
	}
	for(int i=1;i<=n;i++)
	{
		int head=1,tail=0;
		if(2*l[i]>w)
			for(int j=1;j<=w;j++)
			{
				while(head<=tail&&Qu[head]<=j-(w-l[i]+1)) head++;
				if(j<=l[i])
				{
					while(head<=tail&&Ve[i][Qu[tail]]<=Ve[i][j]) tail--;
					Qu[++tail]=j;
				}
				if(j<=w-l[i]||j>=l[i]+1) 
					ans[j]+=max(0,Ve[i][Qu[head]]);
				else ans[j]+=Ve[i][Qu[head]];
			}
		else
		{
			int maxi=0;
			for(int j=1;j<l[i];j++)
			{
				maxi=max(maxi,Ve[i][j]);
				ans[j]+=maxi;
			}
			maxi=0;
			for(int j=w;j>=w-l[i]+2;j--)
			{
				maxi=max(maxi,Ve[i][l[i]+j-w]);
				ans[j]+=maxi;
			}
			maxi=0;
			for(int j=1;j<=l[i];j++)
				maxi=max(maxi,Ve[i][j]);
			ans2[l[i]]+=maxi,ans2[w-l[i]+2]-=maxi;
		}
	}
	for(int i=1;i<=w;i++)
		ans2[i]+=ans2[i-1];
	for(int i=1;i<=w;i++)
		printf("%lld ",ans2[i]+ans[i]);
	return 0;
}