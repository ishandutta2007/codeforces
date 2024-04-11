#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=40005;
int c[N],t,a,b,q,l,r;
signed main()
{
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--)
	{
		cin>>a>>b>>q;
		int n=a*b,s=0;
		for(int i=0;i<n;i++)
			c[i]=i%a%b!=i%b%a,s+=c[i];
		while(q--)
		{
			cin>>l>>r;
			int x=l/n,y=r/n,ans=0;
			if(x==y)
			{
				for(int i=l%n;i<=r%n;i++)
					ans+=c[i];
			}
			else
			{
				for(int i=l%n;i<n;i++)
					ans+=c[i];
				for(int i=0;i<=r%n;i++)
					ans+=c[i];
				ans+=s*(y-x-1);
			}
			cout<<ans<<' ';
		}
		cout<<endl;
	}
	return 0;
}