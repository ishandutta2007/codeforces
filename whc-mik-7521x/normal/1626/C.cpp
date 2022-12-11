#include<bits/stdc++.h>
using namespace std;
const int N=107;
int T,n,k[N],h[N];
long long ans,last;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n; ans=0;
		for(int i=1;i<=n;i++) cin>>k[i];
		for(int i=1;i<=n;i++) cin>>h[i];
		last=n;
		for(int i=n;i>=1;i--)
		{
			if(k[i]-k[i-1]>=h[i])
			{
				int pos=k[i]-h[i];
				ans+=1ll*(k[last]-pos+1)*(k[last]-pos)/2;
				last=i-1;
			}
			else
			{
				int st=h[i]-(k[i]-k[i-1]);
				h[i-1]=max(h[i-1],st);
			}
		}
		cout<<ans<<endl;
	}
}