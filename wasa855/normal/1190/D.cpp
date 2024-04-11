#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define int long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define N 200005
int lowbit(int x){return x&(-x);}
struct Node
{
	int x,y;
};
Node a[N];
int ttx[N],tty[N];
int n;
int t[N];
bool vis[N];
void add(int u,int d)
{
	while(u<=n)
	{
		t[u]+=d;u+=lowbit(u);
	}
}
int query(int u)
{
	int ans=0;
	while(u) ans+=t[u],u-=lowbit(u);
	return ans;
}
bool cmp(Node x,Node y)
{
	if(x.y==y.y) return x.x<y.x;
	return x.y>y.y;
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		a[i].x=read(),a[i].y=read();
		ttx[i]=a[i].x,tty[i]=a[i].y;
	}
	sort(ttx+1,ttx+n+1);
	sort(tty+1,tty+n+1);
	int qx=unique(ttx+1,ttx+n+1)-ttx-1;
	int qy=unique(tty+1,tty+n+1)-tty-1;
//	cout<<qy<<endl;
	for(int i=1;i<=n;i++)
	{
		a[i].x=lower_bound(ttx+1,ttx+qx+1,a[i].x)-ttx;
		a[i].y=lower_bound(tty+1,tty+qy+1,a[i].y)-tty;
	}
	int ans=0;
	int pre=0;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		if(a[i].y==a[i+1].y)
		{
//			cout<<"**"<<i<<endl;
			if(!vis[a[i].x])
			{
				add(a[i].x,1);
				vis[a[i].x]=1;
			}
			pre++;
			continue;
		}
		if(!vis[a[i].x])
		{
			add(a[i].x,1);
			vis[a[i].x]=1;
		}
		pre++;
		int suf=0;
		for(int j=i-pre+1;j<=i;j++)
		{
			ans+=(query(n)-query(a[j].x-1))*(query(a[j].x)-query(suf));
			suf=a[j].x;
		}
		pre=0;
	}
	cout<<ans<<endl;
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}