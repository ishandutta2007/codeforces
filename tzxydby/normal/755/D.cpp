#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int bit[N],n,k;
int sum(int i)
{
	int s=0;
	while(i)
	{
		s+=bit[i];
		i-=i&-i;
	}
	return s;
}
void add(int i,int x)
{
	while(i<=n)
	{
		bit[i]+=x;
		i+=i&-i;	
	}	
}
int main()
{
	scanf("%d%d",&n,&k);
	int now=1;
	long long ans=1;
	for(int i=1;i<=n;i++)
	{
		int t=(now+k-1)%n+1;
		int a=min(now,t),b=max(now,t);
		ans+=min(sum(b-1)-sum(a),sum(a-1)+sum(n)-sum(b))+1;
		add(now,1);
		add(t,1);
		now=t;
		printf("%I64d ",ans);
	}
	printf("\n");
	return 0;
}