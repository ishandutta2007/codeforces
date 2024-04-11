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
#define int long long
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
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%d%c",x[i]," \n"[i==(int)x.size()-1]);}
#define N 1005
int a[N],sum[N],n;
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++)
	{
		if(i&1) sum[i]=sum[i-1]+a[i];
		else sum[i]=sum[i-1]-a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i+=2)
	{
		int sum=0,premin=0;
		for(int j=i+1;j<=n;j++)
		{
			if(j%2==0)
			{
				int tmp=sum-premin;
				if(-premin<=a[i])
				{
					if(tmp<0) ans+=max(0LL,min(a[i]+premin+tmp,a[j])+1);
					else ans+=max(0LL,min(a[i]+premin,a[j]-tmp)+1);
				}
				// printf("^ %d %d - %d\n",i,j,ans);
			}
			if(j&1) sum+=a[j];
			else sum-=a[j];
			premin=min(premin,sum);
		}
	}
	ans-=n/2;
	cout<<ans<<endl;
	return 0;
}