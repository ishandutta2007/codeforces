#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 998244353
#define int long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
int mul(int x,int y){return 1LL*x*y%mod;}
#define N 75
int p2[N],cnt[N];
void work()
{
	memset(cnt,0,sizeof(cnt));
	int n,m;
	cin>>n>>m;
	int sum=0;
	for(int i=1;i<=m;i++)
	{
		int x=read();
		sum+=x;
		for(int j=0;j<=40;j++)
		{
			if(x==p2[j]) cnt[j]++;
		}
	}
	if(sum<n)
	{
		cout<<"-1\n";
		return ;
	}
	int ans=0;
	for(int i=0;i<=60;i++)
	{
		if(n&(1LL<<i))
		{
			if(cnt[i]) cnt[i]--;
			else
			{
				for(int j=i;j<=60;j++)
				{
					if(cnt[j])
					{
						cnt[j]--; break;
					}
					cnt[j]++;
					ans++;
				}
			}
		}
		cnt[i+1]+=cnt[i]/2;
	}
	cout<<ans<<endl;
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int T=read();
	p2[0]=1; for(int i=1;i<=40;i++) p2[i]=p2[i-1]*2;
	while(T--) work();
#ifdef __LOCAL__
	cout<<"Time Used : "<<clock()<<endl;
#endif
	return 0;
}