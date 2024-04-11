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
#define N 100005
struct Node
{
	int dat,from;
};
Node a[N];
int n;
int ans[N];
int res[N];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	n=read();
	for(int i=1;i<=n;i++) a[i].dat=read(),a[i].from=i;
	mt19937 rng(time(NULL));
	while((double)clock()/CLOCKS_PER_SEC<=0.45)
	{
		shuffle(a+1,a+n+1,rng);
		ans[1]=1;
		int gcd1=a[1].dat;
		int gcd2=0;
		for(int i=2;i<=n;i++)
		{
			if(gcd1!=1&&__gcd(gcd1,a[i].dat)<gcd1)
			{
				ans[i]=1;
				gcd1=__gcd(gcd1,a[i].dat);
			}
			else
			{
				ans[i]=2;
				gcd2=a[i].dat;
			}
		}
		if(gcd2==0||gcd1!=1) continue;
		for(int i=1;i<=n;i++)
		{
			if(ans[i]==2)
			{
				gcd2=__gcd(gcd2,a[i].dat);
			}
		}
		if(gcd1==1&&gcd2==1)
		{
			for(int i=1;i<=n;i++)
			{
				res[a[i].from]=ans[i];
			}
			cout<<"YES\n";
			for(int i=1;i<=n;i++)
			{
				printf("%d ",res[i]);
			}
			cout<<"\n";
			return 0;
		}
	}
	cout<<"NO\n";
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}