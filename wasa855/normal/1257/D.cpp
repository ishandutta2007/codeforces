#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define N 200005
struct Node
{
	int p,s;
};
Node b[N];
int c[N];
int a[N];
int st[N][25];
int lg[N];
int query(int l,int r)
{
	int x=lg[r-l+1];
	return max(st[l][x],st[r-(1<<x)+1][x]);
}
void work()
{
	int n=read();
	for(int i=1;i<=n;i++) c[i]=0;
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++) st[i][0]=a[i];
	for(int i=1;i<=20;i++)
	{
		for(int j=1;j+(1<<i)-1<=n;j++)
		{
			st[j][i]=max(st[j][i-1],st[j+(1<<i-1)][i-1]);
		}
	}
	int m=read();
	int maxn=0;
	for(int i=1;i<=m;i++)
	{
		b[i].p=read(),b[i].s=read();
		if(b[i].p>maxn) maxn=b[i].p;
		c[b[i].s]=max(c[b[i].s],b[i].p);
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]>maxn)
		{
			cout<<"-1\n";
			return ;
		}
	}
	for(int i=n-1;i>=1;i--)
	{
		if(c[i+1]>c[i]) c[i]=c[i+1];
	}
//	for(int i=1;i<=n;i++) printf("%d ",c[i]);
	int ans=0;
//	cout<<query(5,6)<<endl;
	for(int i=1;i<=n;i++)
	{
		ans++;
		int l=i,r=n,res;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(c[mid-i+1]>=query(i,mid))
			{
				l=mid+1,res=mid;
			}
			else r=mid-1;
		}
		i=res;
//		printf("%d ",i);
	}
	cout<<ans<<endl;
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	lg[1]=0;
	for(int i=2;i<=200000;i++) lg[i]=lg[i/2]+1;
	int T=read();
	while(T--) work();
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}