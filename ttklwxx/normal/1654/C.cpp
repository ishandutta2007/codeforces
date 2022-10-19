#include<bits/stdc++.h>
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
int a[200005],minn;
map<int,int>ma;
bool find(int x)
{
	if(ma[x]>=1)
	{
		ma[x]--;
		return true;
	}
	if(x<=minn)return false;
	if(find(x/2)==true&&find((x+1)/2)==true)return true;
	return false;
}
signed main()
{
	int t,n,sth,x,y,het=0;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		//n=read();
		ma.clear();
		n=read();
		het=0;
		minn=1121131433448687LL;
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
			minn=min(minn,a[i]);
			ma[a[i]]++;
			het+=a[i];
		}
		if(find(het))printf("YES\n");
		else printf("NO\n");
	}
}