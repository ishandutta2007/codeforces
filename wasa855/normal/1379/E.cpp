#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define fir first
#define sec second
#define mod 998244353
#define ll long long
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
#define N 100005
int fa[N],cnt;
bool ok(int n,int k)
{
	if(n<0) return 0;
	if(n%2==0) return 0;
	if(2*k+3>n) return 0;
	if(k==0)
	{
		for(int i=1;i<=18;i++)
		{
			if((1<<i)-1==n) return 1;
		}
		return 0;
	}
	if(k==1)
	{
		if(n<=4) return 0;
		for(int i=1;i<=18;i++)
		{
			if((1<<i)-1==n) return 0;
		}
	}
	if(k==2)
	{
		if(n==9) return 0;
	}
	return 1;
}
void solve(int n,int k,int f)
{
	if(k==0)
	{
		int R=cnt;
		fa[++cnt]=f;
		for(int i=2;i<=n;i++)
		{
			fa[++cnt]=i/2+R;
		}
		return ;
	}
	if(k==1)
	{
		for(int i=1;i<=18;i++)
		{
			int R=(1<<i)-1;
			int A=n-R-1,B=R;
			if(A>B) swap(A,B);
			if(A*2>B)
			{
				if(ok(n-R-1,1))
				{
					fa[++cnt]=f;
					int X=cnt;
					solve(R,0,X),solve(n-R-1,1,X);
					return ;
				}
			}
			else
			{
				if(ok(n-R-1,0))
				{
					fa[++cnt]=f;
					int X=cnt;
					solve(R,0,X),solve(n-R-1,0,X);
					return ;
				}
			}
		}
		// assert(!ok(n,k));
	}
	if(n==11&&k==3)
	{
		fa[++cnt]=f;
		int R=cnt;
		solve(3,0,R),solve(7,2,R);
		return ;
	}
	if(2*k+3==n)
	{
		fa[++cnt]=f;
		fa[cnt+1]=cnt; cnt++;
		solve(n-2,k-1,cnt-1);
		return ;
	}
	if(k==2)
	{
		if(!ok(n-2,1))
		{
			fa[++cnt]=f; int R=cnt;
			solve(3,0,R),solve(n-4,1,R);
			return ;
		}
	}
	fa[++cnt]=f;
	fa[cnt+1]=cnt; cnt++;
	solve(n-2,k-1,cnt-1);
}
signed main()
{
	int n=read(),k=read();
	if(n%2==0)
	{
		cout<<"NO";
		return 0;
	}
	if(k==0)
	{
		for(int i=1;i<=18;i++)
		{
			if((1<<i)-1==n)
			{
				cout<<"YES\n";
				for(int i=1;i<=n;i++) printf("%d ",i/2);
				return 0;
			}
		}
		cout<<"NO";
		return 0;
	}
	if(2*k+3>n)
	{
		cout<<"NO";
		return 0;
	}
	if(k==1)
	{
		if(n<=4)
		{
			cout<<"NO";
			return 0;
		}
		for(int i=1;i<=18;i++)
		{
			if((1<<i)-1==n)
			{
				cout<<"NO";
				return 0;
			}
		}
	}
	if(k==2)
	{
		if(n==9)
		{
			cout<<"NO";
			return 0;
		}
	}
	solve(n,k,0);
	cout<<"YES\n";
	for(int i=1;i<=n;i++) printf("%d ",fa[i]);
	return 0;
}