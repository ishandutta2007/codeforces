#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans; return ans;
}
#define N 5005
struct Node
{
	int x1,y1,x2,y2;
};
Node a[N],b[N];
int n;
bitset<N> s[N];
bitset<N> x;
bool judge(Node x,Node y)
{
	if(y.y1<=x.y1&&x.y1<=y.y2&&x.x1<=y.x1&&y.x1<=x.x2) return true;
	return false;
}
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	cin>>n;
	int c,d,e,f;
	int sa=0,sb=0;
	for(int i=1;i<=n;i++)
	{
		c=read(),d=read(),e=read(),f=read();
		if(c==e)
		{
			if(d>f) swap(d,f);
			b[++sb].x1=c;
			b[sb].y1=d;
			b[sb].x2=e;
			b[sb].y2=f;
		}
		else
		{
			if(c>e) swap(c,e);
			a[++sa].x1=c;
			a[sa].y1=d;
			a[sa].x2=e;
			a[sa].y2=f;
		}
	}
	if(sa<sb)
	{
		for(int i=1;i<=sa;i++)
		{
			s[i].reset();
			for(int j=1;j<=sb;j++)
			{
				if(judge(a[i],b[j]))
				{
					s[i].set(j);
				}
			}
		}
		int ans=0;
		for(int i=1;i<=sa;i++)
		{
			for(int j=i+1;j<=sa;j++)
			{
				x.reset();
				x=s[i]&s[j];
				int dat=x.count();
				ans+=dat*(dat-1)/2;
			}
		}
		cout<<ans<<endl;
	}
	else
	{
		for(int i=1;i<=sb;i++)
		{
			s[i].reset();
			for(int j=1;j<=sa;j++)
			{
				if(judge(a[j],b[i]))
				{
					s[i].set(j);
				}
			}
		}
		int ans=0;
		for(int i=1;i<=sb;i++)
		{
			for(int j=i+1;j<=sb;j++)
			{
				x.reset();
				x=s[i]&s[j];
				int dat=x.count();
				ans+=dat*(dat-1)/2;
			}
		}
		cout<<ans<<endl;
	}
#ifndef ONLINE_JUDGE
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}