#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	int ans=0;
	while(isdigit(ch))
	{
		ans=ans*10+ch-48;
		ch=getchar();
	}
	return ans;
}
#define N 105
int a[N];
int sum[N];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%1d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	int tot=sum[n];
	if(tot*2!=n)
	{
		cout<<"1\n";
		for(int i=1;i<=n;i++)
		{
			printf("%d",a[i]);
		}
		return 0;
	}
	int minn=0;
	for(int i=1;i<n;i++)
	{
		if(sum[i]*2!=i)
		{
			if((tot-sum[i])*2!=(n-i))
			{
				cout<<"2\n";
				for(int c=1;c<=i;c++)
				{
					printf("%d",a[c]);
				}
				cout<<" ";
				for(int c=i+1;c<=n;c++)
				{
					printf("%d",a[c]);
				}
				return 0;
			}
		}
	}
	
	for(int i=1;i<n;i++)
	{
		if(sum[i]*2==i) continue;
		for(int j=i+1;j<n;j++)
		{
			if((sum[j]-sum[i])*2==(j-i)) continue;
			if((tot-sum[j])*2!=(n-j))
			{
				cout<<"3\n";
				for(int c=1;c<=i;c++)
				{
					printf("%d",a[c]);
				}
				cout<<" ";
				for(int c=i+1;c<=j;c++)
				{
					printf("%d",a[c]);
				}
				cout<<" ";
				for(int c=j+1;c<=n;c++)
				{
					printf("%d",a[c]);
				}
				return 0;
			}	
		}
	}
	return 0;
}

//asc