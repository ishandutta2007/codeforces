#include <bits/stdc++.h>
using namespace std;
const int Maxn=100005;
int n,a[Maxn],pos,sam;
long long sum;
bool vis[Maxn];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++)
		if(a[i]==a[i+1]) sam++,pos=i;
	if(sam>=2)
	{
		printf("cslnb");
		return 0;
	}
	if(sam==1)
	{
		if(!a[pos])
		{
			printf("cslnb");
			return 0;
		}
		a[pos]--;
		if(pos>1&&a[pos-1]==a[pos])
		{
			printf("cslnb");
			return 0;
		}
		sum++;
	}
	for(int i=1;i<=n;i++)
		sum+=a[i]-i+1;
	if(sum&1) printf("sjfnb");
	else printf("cslnb");
	return 0;
}