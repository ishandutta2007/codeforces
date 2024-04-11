#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 998244353
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
int add(int x,int y){return x+y>mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
#define N 100005
int s[N];
int sum[N];
int cnt[N*2];
void work()
{
	int n=read(),x=read();
	for(int i=1;i<=n;i++) scanf("%1d",&s[i]);
	for(int i=1;i<=n;i++) cnt[i]=0;
	int minn=n+5,maxn=-n-5;
	for(int i=1;i<=n;i++)
	{
		if(s[i]==1) sum[i]=sum[i-1]-1;
		else sum[i]=sum[i-1]+1;
		cnt[sum[i]+N]++;
		if(sum[i]>maxn) maxn=sum[i];
		if(sum[i]<minn) minn=sum[i];
	}
	int xx=sum[n];
	if(xx==0)
	{
		for(int i=0;i<=n;i++)
		{
			if(sum[i]==x)
			{
				cout<<"-1\n";
				return ;
			}
		}
		cout<<"0\n";
		return ;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if((x-sum[i])%xx==0&&(x-sum[i])/xx>=0) ans++;
	}
	if(sum[0]==x) ans++;
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
	cout<<"Time Used : "<<clock()<<endl;
#endif
	return 0;
}