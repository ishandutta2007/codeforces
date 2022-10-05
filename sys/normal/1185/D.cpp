#include <bits/stdc++.h>
using namespace std;
const int Maxn=200005;
int cnt,n,a[Maxn],diff[Maxn],b[Maxn];
map<int,int> Ma;
void del(int x)
{
	Ma[x]--;
	if(Ma[x]==0)
		cnt--;
}
void add(int x)
{
	if(Ma[x]==0)
		cnt++;
	Ma[x]++;
}
void print(int val)
{
	for(int i=1;i<=n;i++)
		if(b[i]==val)
		{
			printf("%d",i);
			return ;
		}
}
int main()
{
	scanf("%d",&n);
	if(n<=3)
	{
		printf("1");
		return 0;
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),b[i]=a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)
		diff[i]=a[i+1]-a[i],add(diff[i]);
	for(int i=1;i<=n;i++)
	{ 
		if(i==n)
		{
			del(diff[n-1]);
			if(cnt==1)
			{
				print(a[n]);
				return 0;
			}
			add(diff[n-1]);
		}
		else if(i==1)
		{
			del(diff[1]);
			if(cnt==1)
			{
				print(a[1]);
				return 0;
			}
			add(diff[1]);
		}
		else
		{
			del(diff[i-1]);
			del(diff[i]);
			add(diff[i-1]+diff[i]);
			if(cnt==1)
			{
				print(a[i]);
				return 0;
			}
			add(diff[i]);
			add(diff[i-1]);
			del(diff[i-1]+diff[i]);
		}
	}
	printf("-1");
	return 0;
}