#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
int n,prime[5000005],a[500005],b[500005],mind[5000005],num,top1,top2;
bool flag[5000005];
map<int,int>s;
void pre(int n)
{
	flag[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(!flag[i])
		{
			prime[++num]=i;
			mind[i]=i;
		}
		for(int j=1;j<=num&&prime[j]*i<=n;j++)
		{
			flag[i*prime[j]]=1;
			mind[i*prime[j]]=min(mind[i],prime[j]);
			if(i%prime[j]==0)break;
		}
	}
}
int main()
{
	pre(5000000);
	scanf("%d",&n);
	for(int i=1;i<=2*n;i++)
	{
		int x;
		scanf("%d",&x);
		if(flag[x])b[++top2]=x;
		else a[++top1]=x;
	}
	sort(b+1,b+top2+1);
	sort(a+1,a+top1+1);
	for(int i=top2;i>=1;i--)
	{
		if(s[b[i]])
		{
			s[b[i]]--;
			continue;
		}
		printf("%d ",b[i]);
		s[b[i]/mind[b[i]]]++;
	}
	for(int i=1;i<=top1;i++)
	{
		if(s[a[i]])
		{
			s[a[i]]--;
			continue;
		}
		printf("%d ",a[i]);
		s[prime[a[i]]]++;
	}
	printf("\n");
	return 0;
}