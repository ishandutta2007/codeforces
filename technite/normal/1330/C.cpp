#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,m;
	cin>>n>>m;
	long long a[m],sum=0;
	for(long long i=0;i<m;i++) 
	{
		cin>>a[i];
		sum+=a[i];
		if(a[i]+i>n) {cout<<"-1";return 0;}
	}
	long long k=sum-n,f,z,ans[n]={0};
	ans[0]=1;
	if(sum<n) {cout<<-1;return 0;}
	
	else
	{
		
		for(int i=0;i<m-1;i++) 
			{
				
				if(k==0)
				{
					ans[i+1]=ans[i]+a[i];
				}
				else
				{
					if(k>=a[i])
					{
						k=k-a[i]+1;
						ans[i+1]=ans[i]+1;
					}
					else
					{
						ans[i+1]=ans[i]+a[i]-k;
						k=0;
					}
				}
			}
	}
	for(int i=0;i<m;i++) cout<<ans[i]<<" ";
 
}