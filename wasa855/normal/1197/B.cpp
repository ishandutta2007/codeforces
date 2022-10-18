#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define N 200005
int a[N];
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	int n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	int maxn=0;
	for(int i=1;i<=n;i++)
	{
		if(a[maxn]<a[i]) maxn=i;
	}
	for(int i=1;i<maxn;i++)
	{
		if(a[i+1]<a[i])
		{
			cout<<"NO\n";
			return 0;
		}
	}
	for(int i=maxn;i<n;i++)
	{
		if(a[i+1]>a[i])
		{
			cout<<"NO\n";
			return 0;
		}
	}
	cout<<"YES\n";
#ifndef ONLINE_JUDGE
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}