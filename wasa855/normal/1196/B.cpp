#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define N 200005
int a[N];
int ans[N];
void work()
{
	int n,k;
	cin>>n>>k;
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		sum+=a[i];
	}
	if(sum%2!=k%2)
	{
		cout<<"NO\n";
		return ;
	}
	int res=0,tot=0;
	for(int i=1;i<=n;i++)
	{
		res+=a[i];
		if(res%2==1)
		{
			res=0,tot++;
			ans[tot]=i;
			if(tot==k)
			{
				ans[tot]=n;
				break;
			}
		}
	}
	if(tot==k)
	{
		cout<<"YES\n";
		for(int i=1;i<=k;i++) printf("%d ",ans[i]);
		cout<<"\n";
	}
	else
	{
		cout<<"NO\n";
	}
}
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	int T=read();
	while(T--) work();
#ifndef ONLINE_JUDGE
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}