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
int b[N];
bool cmp(int x,int y)
{
	return x>y;
}
signed main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%I64d",&a[i]);
	}
	for(int i=n;i>=1;i--)
	{
		b[i]=b[i+1]+a[i];
	}
//	for(int i=1;i<=n;i++)
//	{
//		printf("%I64d ",b[i]);
//	}
//	cout<<"\n";
	sort(b+2,b+n+1,cmp);
	int ans=b[1];
	for(int i=2;i<=m;i++)
	{
		ans+=b[i];
	}
	cout<<ans<<endl;
	return 0;
}