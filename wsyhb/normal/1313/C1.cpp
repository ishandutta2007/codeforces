#include<bits/stdc++.h>
#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b
using namespace std;
typedef long long ll;
const int N=1e3+5;
int m[N],now[N],ans[N];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",m+i);
	ll Max=0;
	for(int i=1;i<=n;i++)
	{
		ll tot=m[i];
		now[i]=m[i];
		for(int j=i-1;j>=1;j--)
		{
			now[j]=min(m[j],now[j+1]);
			tot+=now[j];
		}
		for(int j=i+1;j<=n;j++)
		{
			now[j]=min(m[j],now[j-1]);
			tot+=now[j];
		}
		if(tot>Max)
		{
			Max=tot;
			for(int i=1;i<=n;i++) ans[i]=now[i];
		}
	}
	for(int i=1;i<=n;i++) printf("%d%c",ans[i],i<n?' ':'\n');
	return 0;
}