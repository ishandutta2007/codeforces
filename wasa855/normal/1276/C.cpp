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
#define N 400005
int n,m;
struct Node
{
	int cnt,b;
};
Node b[N];
int x[N];
bool cmp(Node x,Node y)
{
	return x.cnt<y.cnt;
}
int a[N];
int d[N];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	cin>>n;
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=a[i-1]) m++,b[m].b=a[i];
		b[m].cnt++;
	}
	sort(b+1,b+m+1,cmp);
//	for(int i=1;i<=m;i++)
//	{
//		printf("%d %d\n",b[i].b,b[i].cnt);
//	}
	int mx=0,my=0,sum=0,pl=0;
	int bx=0;
	for(int i=1;i<=n;i++)
	{
		int las=bx;
		while(bx<m&&b[bx+1].cnt<=i) sum+=b[++bx].cnt;
		if(sum+i*(m-bx)>=i*i)
		{
			int tx=i,ty=(sum+i*(m-bx))/i;
			if(tx*ty>mx*my)
			{
				mx=tx,my=ty,pl=las;
			}
		}
	}
//	cout<<pl<<endl;
	printf("%lld\n%lld %lld\n",mx*my,mx,my);
	int ans[mx+1][my+1];
	memset(ans,0,sizeof(ans));
	int cm=0;
	for(int i=pl+1;i<=m;i++)
	{
		for(int j=1;j<=mx;j++) x[++cm]=b[i].b;
	}
	for(int i=1;i<=pl;i++)
	{
		for(int j=1;j<=b[i].cnt;j++) x[++cm]=b[i].b;
	}
//	cout<<cm<<endl;
//	for(int i=1;i<=cm;i++) printf("%d ",x[i]);
//	cout<<"\n";
	int cnt=0;
	for(int i=1;i<=my;i++)
	{
		for(int j=1;j<=mx;j++)
		{
			ans[j][(i+j-2)%my+1]=x[++cnt];
		}
	}
	bool ok=1;
	for(int i=1;i<=mx;i++)
	{
		for(int j=1;j<=my;j++) d[j]=ans[i][j];
		sort(d+1,d+my+1);
		for(int j=1;j<my;j++) if(d[j]==d[j+1]) ok=0;
	}
	for(int i=1;i<=my;i++)
	{
		for(int j=1;j<=mx;j++) d[j]=ans[j][i];
		sort(d+1,d+mx+1);
		for(int j=1;j<mx;j++) if(d[j]==d[j+1]) ok=0;
	}
	if(ok==0)
	{
		return 1;
	}
	for(int i=1;i<=mx;i++)
	{
		for(int j=1;j<=my;j++)
		{
			printf("%lld ",ans[i][j]);
		}
		cout<<"\n";
	}
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}