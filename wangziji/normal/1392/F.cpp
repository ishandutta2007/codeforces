#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
int a[1000005],qwq[1000005],b[1000005];
int n,s;
inline void qaq()
{
//	for(int i=1;i<=n;i++)
//		cout << b[i] << " ";
//	puts("");
	for(int i=1;i<=n;i++) a[i]=b[i];
	while(1)
	{
		int flag=0;
		for(int i=1;i<n;i++)
		{
			if(a[i]+2<=a[i+1])
				qwq[i]=1,flag=1;
			else qwq[i]=0;
		}
		for(int i=1;i<=n;i++)
			if(qwq[i]) ++a[i],--a[i+1];
		if(!flag) break;
	}
	for(int i=1;i<=n;i++)
		cout << a[i] << " ";
	puts("");
}
inline void dfs(int x,int lst,int s)
{
	if(x==n&&s<=lst) return ;
	if(x==n)
	{
		b[n]=s;
		qaq();
		return ;
	}
	for(int i=lst+1;i<=s;i++)
		b[x]=i,dfs(x+1,i,s-i);
}
signed main(int argc, char** argv) {
	cin >> n;
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]),s+=a[i];
//	dfs(1,0,s);
	int l=0,r=1.5e12,ans=0;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if((mid+(mid+n-1))*n/2<=s) ans=mid,l=mid+1;
		else r=mid-1;
	}
	for(int i=1;i<=n;i++)
		b[i]=ans+i-1;
	s-=(ans+(ans+n-1))*n/2;
	for(int i=1;i<=n;i++)
	{
		if(s) ++b[i],--s;
	}
	for(int i=1;i<=n;i++)
		printf("%lld ",b[i]);
	return 0;
}