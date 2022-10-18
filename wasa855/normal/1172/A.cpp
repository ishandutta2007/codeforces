#include<bits/stdc++.h>
using namespace std;
#define N 200005
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
int a[N],b[N];
signed main()
{
	int n;
	cin>>n;
	int maxn=0;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	int one=-1;
	for(int i=1;i<=n;i++)
	{
		b[i]=read();
		if(b[i])
		{
			maxn=max(i-b[i]+1,maxn);
		}
		if(b[i]==1) one=i;
	}
	bool ok=true;
	if(one==-1) ok=false;
	if(ok!=-1)
	{
		for(int i=one;i<=n;i++)
		{
			if(b[i]!=i-one+1)
			{
				ok=false;
			}
		}
	}
	if(ok==true)
	{
		int deal=b[n];
		maxn=-1e10;
		for(int i=1;i<one;i++)
		{
			if(b[i])
			{
				maxn=max(i-(b[i]-b[n]-1),maxn);
			}
		}
		if(maxn<=0)
		{
			cout<<n-b[n]<<endl;
			return 0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i])
		{
			maxn=max(i-b[i]+1,maxn);
		}
	}
	cout<<maxn+n<<endl;
	return 0;
}
//ytfku