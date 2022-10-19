#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=10005;
int n,m,k,a[N],x,r,g;
void zh(){cout<<"NO"<<endl;exit(0);}
int exgcd(int a,int b,int &x,int &y)
{
	if(b==0)
	{
		x=1,y=0;
		return a;
	}
	int r=exgcd(b,a%b,x,y);
	int t=x;x=y,y=t-a/b*y;
	return r;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m>>k>>a[1];
	if(a[1]>n) zh();
	g=a[1];
	for(int i=2;i<=k;i++)
	{
		cin>>a[i];
		int x,y,d=exgcd(g,a[i],x,y);
		if((i-1+r)%d) zh();
		x=(x*(-i+1-r)/d)%(a[i]/d);
		r+=x*g;
		g=g/d*a[i];
		if(g>n) zh();
		r=(r%g+g)%g;
	}
	if(!r) r=g;
	if(r+k-1>m) zh();
	for(int i=1;i<=k;i++)
		if(__gcd(g,r+i-1)!=a[i])
			zh();
	cout<<"YES"<<endl;
	return 0;
}