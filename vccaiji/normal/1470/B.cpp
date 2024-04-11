#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
bool l[1100000]={};
int d[1100000]={};
void init()
{
	for(int i=2;i<=1000;i++)
	{
		int u=1000000/(i*i);
		for(int j=1;j<=u;j++) l[i*i*j]=true;
	}
	for(int i=1;i<=1000000;i++)
	{
		if(!l[i])
		{
			for(int j=1;j*j*i<=1000000;j++)
			d[j*j*i]=i;
		}
	}
}
int a[400000];
int main()
{
	std::ios::sync_with_stdio(0);
	init();
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int n;
		cin>>n;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j];
			a[j]=d[a[j]];
		}
		sort(a+1,a+n+1);
		int o1=0,o2;
		int cur=1,s1=0;
		for(int j=1;j<=n;j++)
		{
			if(a[j]==a[cur]) continue;
			if(o1<j-cur) o1=j-cur;
			if((a[cur]==1)||((j-cur)%2==0))
			s1+=j-cur;
			cur=j;
		}
		if(o1<n+1-cur) o1=n+1-cur;
		if((a[cur]==1)||((n+1-cur)%2==0))
		s1+=n+1-cur;
		o2=max(o1,s1);
		int q;
		cin>>q;
		for(int j=1;j<=q;j++)
		{
			long long w;
			cin>>w;
			if(w) cout<<o2;
			else cout<<o1;
			if((j<q)||(i<t)) cout<<endl;
		}
	}
	return 0;
}