//CF 800C
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
int n,f[222222],g[222222],s[222222],a[22],dp[222222],pa[222222],b[22];
vector<int> v[222222];
int gcd(int x,int y)
{
	if(x<y)
		swap(x,y);
	int r;
	r=x%y;
	while(r){
		x=y;
		y=r;
		r=x%y;
	}
	return y;
}
int exgcd(int a,int b,int &xx,int &yy)
{
	if(b==0){
		xx=1;
		yy=0;
		return a;
	}
	int t;
	t=exgcd(b,a%b,yy,xx);
	yy-=a/b*xx;
	return t;
}
int main()
{
	int m,i,x,t,l,j,p,xx,yy;
	cin>>m>>n;
	for(i=1;i<=m;i=i+1){
		cin>>x;
		f[x]=1;
	}
	for(i=1;i<n;i=i+1){
		g[i]=gcd(i,n);
		if(f[i]==0){
			s[g[i]]++;
			v[g[i]].push_back(i);
		}
	}
	g[n]=n;
	l=0;
	t=n;
	for(i=2;i*i<=n&&t!=1;i=i+1){
		if(n%i==0){
			l++;
			a[l]=i;
		}
		while(t%i==0){
			t/=i;
		}
	}
	if(t!=1){
		l++;
		a[l]=t;
	}
	dp[1]=s[1];
	pa[1]=1;
	for(i=1;i<n;i=i+1){
		if(g[i]!=i)
			continue;
		for(j=1;j<=l;j=j+1)
			if(i*a[j]<=n&&g[i*a[j]]==i*a[j])
				if(dp[i*a[j]]<dp[i]+s[i*a[j]]){
					dp[i*a[j]]=dp[i]+s[i*a[j]];
					pa[i*a[j]]=i;
				}
	}
	l=0;
	t=n;
	j=0;
	while(t!=1){
		t=pa[t];
		l++;
		b[l]=t;
		j+=s[t];
	}
	if(f[0]==0)
		j++;
	cout<<j<<endl;
	p=1;
	for(i=l;i>=1;i=i-1)
	{
		for(j=0;j<s[b[i]];j=j+1)
		{
			exgcd(p/g[p],n/g[p],xx,yy);
			xx+=n/g[p];
			//xx=(long long)xx*g[p]%n;
			cout<<(long long)(v[b[i]][j]/g[p])*xx%n<<' ';
			p=v[b[i]][j];
		}
	}
	if(f[0]==0)
		cout<<0<<' ';
	return 0;
}