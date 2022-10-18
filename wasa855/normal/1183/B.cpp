#include<bits/stdc++.h>
using namespace std;
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
#define N 105
int a[N];
void work()
{
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++) a[i]=read();
	int minn=1e9,maxn=0;
	for(int i=1;i<=n;i++)
	{
		minn=min(minn,a[i]),maxn=max(maxn,a[i]);
	}
	if(maxn-minn>2*k) cout<<"-1\n";
	else
	{
		cout<<minn+k<<endl;
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	int T;
	cin>>T;
	while(T--)
	{
		work();
	}
	return 0;
}