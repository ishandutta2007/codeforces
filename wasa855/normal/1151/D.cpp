#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans; return ans;
}
#define N 100005
int a[N];
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	int n,ans=0;
	n=read();
	int x,y;
	for(int i=1;i<=n;i++)
	{
		x=read(),y=read();
		ans-=x;
		ans+=n*y;
		a[i]=x-y;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		ans+=a[i]*(n-i+1);
	}
	cout<<ans<<endl;
#ifndef ONLINE_JUDGE
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}