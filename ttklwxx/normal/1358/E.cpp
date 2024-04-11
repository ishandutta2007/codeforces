#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#define int long long
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
int n,x,a[500003],m=1e18;
signed main()
{
	n=read();
	for(int i=1;i<=(n+1)/2;++i)a[i]=read();
	x=read();
	for(int i=(n+1)/2;i;--i)a[i]=a[i+1]+a[i]-x;
	for(int i=1;i<=(n+1)/2;++i){
		if(a[i]<m)m=a[i];
		if(m>(i-n-1)*x){
			cout<<n+1-i;
			return 0;
		}
	}
	cout<<-1;
}