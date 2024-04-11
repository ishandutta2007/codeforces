#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 300005
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
int a[N];
signed main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	int ans=0,res=0;
	for(int i=n;i>=1;i--)
	{
		res+=a[i]/2;
		if(a[i]%2&&res)
		{
			ans++;
			res--;
		}
	}
	ans+=res*2/3;
	cout<<ans<<endl;
	return 0;
}