#include<bits/stdc++.h>
using namespace std;
const int N=205;
string ans;
int x[N],y[N],n,m,k,a[N],b[N];
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;i++)
		scanf("%d%d",&x[i],&y[i]);
	for(int i=1;i<=k;i++)
		scanf("%d%d",&a[i],&b[i]);
	for(int i=1;i<n;i++)
		ans+='U';
	for(int i=1;i<m;i++)
		ans+='L';
	for(int i=1;i<=n;i++)
	{
		if(i%2)
		{
			for(int j=1;j<m;j++)
				ans+='R';
		}
		else
		{
			for(int j=1;j<m;j++)
				ans+='L';
		}
		if(i!=n)
			ans+='D';
	}
	cout<<ans.size()<<endl<<ans<<endl;
	return 0;
}