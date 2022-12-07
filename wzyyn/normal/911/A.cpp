#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio> 
#include<algorithm>
#include<map>
#define ll long long 
#define For(i,j,k)	for(int i=j;i<=k;++i)
#define Dow(i,j,k)	for(int i=k;i>=j;--i)
using namespace std;
inline ll read()
{
	ll t=0,f=1;char tmp=getchar();
	while(tmp<'0'||tmp>'9')	{if(tmp=='-')	f=-1;tmp=getchar();}
	while(tmp>='0'&&tmp<='9')	t=t*10+tmp-48,tmp=getchar();
	return t*f;
}
int n,ans=1e9;
int last,x=1e9+1,a[200001];
int main()
{
	n=read();
	For(i,1,n)	a[i]=read();
	For(i,1,n)	x=min(x,a[i]);
	For(i,1,n)
	{
		if(a[i]!=x)	continue;
		if(last)	ans=min(ans,i-last);
		last=i;
	}
	cout<<ans<<endl;
}