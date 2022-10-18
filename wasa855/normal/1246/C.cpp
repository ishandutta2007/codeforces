#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define int long long
#define mod 1000000007
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define N 2005
int lowbit(int x)
{
	return x&(-x);
}
char s[N][N];
int f[N][N];
int c1[N][N],c2[N][N];
struct BIT
{
	int c[N];
	void add(int x,int d)
	{
		for(;x<=2000;x+=lowbit(x))
		{
			c[x]=(c[x]+d)%mod;
		}
	}
	void sub(int x,int d)
	{
		for(;x<=2000;x+=lowbit(x))
		{
			c[x]=(c[x]-d)%mod;
			c[x]=(c[x]+mod)%mod;
		}
	}
	int query(int x)
	{
		int ans=0;
		for(;x>0;x-=lowbit(x))
		{
			ans=(ans+c[x])%mod;
		}
		return ans;
	}
};
BIT t1[N],t2[N];
void work1(int u,int l,int r,int d)
{
	t1[u].add(l,d);
	t1[u].sub(r+1,d);
}
void work2(int u,int l,int r,int d)
{
	t2[u].add(l,d);
	t2[u].sub(r+1,d);
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n,m;
	cin>>n>>m;
	if(n==1&&m==1)
	{
		cout<<"1\n";return 0;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s[i]+1);
	}
	for(int i=1;i<=n;i++)
	{
		int cnt=0;
		for(int j=1;j<=m;j++)
		{
			cnt+=(s[i][j]=='R');
			c1[i][j]=cnt;
		}
	}
	for(int i=1;i<=m;i++)
	{
		int cnt=0;
		for(int j=2;j<=n;j++)
		{
			cnt+=(s[j][i]=='R');
			c2[j][i]=cnt;
		}
	}
	work1(1,1,1,1);
	work2(1,1,1,1);
	int aa=0,ab=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			aa=t1[i].query(j);
			ab=t2[j].query(i);
			int sum=c1[i][m]-c1[i][j];
			work1(i,j+1,m-sum,ab);
			sum=c2[n][j]-c2[i][j];
			work2(j,i+1,n-sum,aa);
		}
	}
	int ans=(aa+ab)%mod;
	ans=(ans+mod)%mod;
	cout<<ans<<endl;
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}