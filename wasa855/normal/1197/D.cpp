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
#define N 300005
int a[N],b[N];
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) a[i]=read();
	int ans=0;
	for(int j=0;j<m;j++)
	{
		for(int i=1;i<=n;i++)
		{
			b[i]=a[i]-((i%m==j)?k:0);
		}
		int x=0;
		for(int i=1;i<=n;i++)
		{
			x=max(x+b[i],0LL);
			if(i%m==j) ans=max(ans,x);
		}
	}
	cout<<ans<<endl;
#ifndef ONLINE_JUDGE
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}