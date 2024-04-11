#include<bits/stdc++.h>
using namespace std;
#define int long long
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
int a[20];
int f[20][5];
int work(int pos,int lim,bool use)
{
	if(pos==-1) return 1;
	if(!use&&f[pos][lim]!=-1) return f[pos][lim];
	int xx=use?a[pos]:9;
	int ans=0;
	for(int i=0;i<=xx;i++)
	{
		if(i==0)
		{
			if(use&&a[pos]==0) ans+=work(pos-1,lim,true);
			else ans+=work(pos-1,lim,false);
			continue;
		}
		if(lim==3) break;
		if(use&&a[pos]==i) ans+=work(pos-1,lim+1,true);
		else ans+=work(pos-1,lim+1,false);
	}
	if(!use) return f[pos][lim]=ans;
	return ans;
}
int count(int x)
{
	int sum=0;
	while(x)
	{
		a[sum]=x%10;
		x/=10;
		sum++;
	}
	return work(sum-1,0,true);
}
signed main()
{
	memset(f,-1,sizeof(f));
	int T;
	cin>>T;
	int l,r;
	for(int i=1;i<=T;i++)
	{
		l=read(),r=read();
		cout<<(count(r)-count(l-1))<<endl;
	}
	return 0;
}