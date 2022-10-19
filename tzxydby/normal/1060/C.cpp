#include<bits/stdc++.h>
using namespace std;
const int N=2005;
long long a[N],b[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,m,x,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]+=a[i-1];
	}
	for(int i=1;i<=m;i++)
	{
		cin>>b[i];
		b[i]+=b[i-1];
	}
	cin>>x;
	for(int i=1;i<=n;i++)
	{
		long long minf=INT_MAX,maxd=0;
		for(int j=i;j<=n;j++)
			minf=min(minf,a[j]-a[j-i]);
		for(long long lb=1,ub=1;ub<=m;lb++)
		{
			while(ub<=m&&(b[ub]-b[lb-1])*minf<=x)
				ub++;
			ub--;
			maxd=max(maxd,ub-lb+1);
			if(ub==m)
				break;
		}
		ans=max(ans,i*maxd);
	}
	cout<<ans<<endl; 
	return 0;
}