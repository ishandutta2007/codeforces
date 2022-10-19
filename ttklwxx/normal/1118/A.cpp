#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
inline ll read()
{
	ll n=0,f=1,ch=getchar();
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
int main()
{
	ll q,n,a,b;
	q=read();
	for(int i=1;i<=q;i++)
	{
		n=read();
		a=read();
		b=read();
		cout<<min(a*n,b*(n/2)+a*(n%2))<<endl;
	}
	return 0;
}