#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=105;
int a[N];
signed main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,k;
		cin>>n>>m>>k;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		int flag=1;
		for(int i=1;i<n;i++)
		{
			if(a[i]>a[i+1])
				m+=a[i]-max(a[i+1]-k,0LL);
			else
			{
				if(a[i]+m<a[i+1]-k)
					flag=0;
				else
				{
					if(a[i]>=a[i+1]-k)
					{
						m+=a[i]-max(a[i+1]-k,0LL);
					}
					else
					{
						m-=(a[i+1]-k)-a[i];
					}
				}
			}
		}
		cout<<(flag?"YES":"NO")<<endl;
	}
	return 0;
}