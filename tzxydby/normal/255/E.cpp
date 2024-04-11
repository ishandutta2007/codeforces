#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1000005;
int n,a[N],s[5][N],x,v;
int s4(int x)
{
	int l=0,r=min(x-1,2000LL);
	while(r-l>1)
	{
		int m=l+r>>1;
		if(m*m*m*m<x)
			l=m;
		else
			r=m;
	}
	return l+1;
}
int s2(int x)
{
	int l=0,r=min(x-1,2000000LL);
	while(r-l>1)
	{
		int m=l+r>>1;
		if(m*m>x)
			r=m;
		else
			l=m;
	}
	return r-1;
}
int sg(int x)
{
	if(x<=1000000)
		return a[x];
	int t=0,l=s4(x),r=s2(x);
	while(s[t][r]-s[t][l-1])
		t++;
	return t;
}
signed main()
{
	ios::sync_with_stdio(0);
	for(int i=1;i<=1000000;i++)
	{
		if(i>60000)
			a[i]=a[i-1];
		else
		{
			int v[10];
			for(int j=0;j<10;j++)
				v[j]=0;
			for(int j=s4(i);j<=s2(i);j++)
				v[a[j]]=1;
			for(int j=0;;j++)
			{
				if(!v[j])
				{
					a[i]=j;
					break;
				}
			}
		}
		for(int j=0;j<5;j++)
			s[j][i]=s[j][i-1];
		s[a[i]][i]++;
	}
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		v^=sg(x);
	}
	cout<<(v?"Furlo":"Rublo")<<endl;
	return 0;
}