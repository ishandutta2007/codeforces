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
int p[N];
int x,a,y,b,k;
int n;
bool cmp(int x,int y)
{
	return x>y;
}
bool judge(int mid)
{
	int bot=mid/(a/__gcd(a,b)*b);
	int c=mid/a-bot,d=mid/b-bot;
//	printf("%I64d %I64d %I64d %I64d\n",mid,bot,c,d);
	int ans=0;
	for(int i=1;i<=bot;i++) ans+=p[i]*(x+y);
	for(int i=bot+1;i<=c+bot;i++) ans+=p[i]*x;
	for(int i=bot+c+1;i<=d+c+bot;i++) ans+=p[i]*y;
//	cout<<ans<<endl;
	return ans>=k;
}
void work()
{
	int n=read();
	for(int i=1;i<=n;i++) p[i]=read()/100;
	cin>>x>>a>>y>>b>>k;
	if(x<y) swap(x,y),swap(a,b);
	sort(p+1,p+n+1,cmp);
	if(!judge(n))
	{
		cout<<"-1\n";return ;
	}
	int l=0,r=n,mid,ans=0;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(judge(mid))
		{
			r=mid-1,ans=mid;
		}
		else l=mid+1;
	}
	cout<<ans<<endl;
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int T=read();
	while(T--) work();
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}