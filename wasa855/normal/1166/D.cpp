#include<bits/stdc++.h>
using namespace std;
#define int long long
int r[55];
int a,b,m;
int Do(int n)
{
	int x=b-a*(1LL<<(n-2))-(1LL<<(n-2));
	if(x<0) return 2;
//	cout<<x<<" ";
	for(int i=2;i<n;i++)
	{
		r[i]=min(m-1,x/(1LL<<n-i-1));
		x-=r[i]*(1LL<<n-i-1);
	}
//	printf("%d : ",n);
//	for(int i=2;i<=n;i++)
//	{
//		printf("%I64d ",r[i]);
//	}
//	cout<<"\n";
	if(x<m)
	{
		r[n]=x;
		return 1;
	}
	return 0;
}
void work()
{
	cin>>a>>b>>m;
	if(a==b)
	{
		printf("1 %I64d\n",a);
		return ;
	}
	r[1]=a;
	for(int i=2;i<=50;i++)
	{
		int opt=Do(i);
		if(opt==2) break;
		if(opt==1)
		{
			cout<<i<<" ";
			for(int j=2;j<=i;j++) r[j]++;
			int sum=a;
			for(int j=2;j<=i;j++)
			{
				r[j]+=sum;
				sum+=r[j];
			}
			for(int j=1;j<=i;j++)
			{
				cout<<r[j]<<" ";
			}
			cout<<"\n";
			return ;
		}
	}
	cout<<"-1\n";
}
signed main()
{
	int T;
	cin>>T;
	while(T--)
	{
		work();
	}
	return 0;
}