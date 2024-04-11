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
void work()
{
	int a=read(),b=read();
	// if(b%a==0) {printf("0\n"); return ;}
	if(a%b!=0) {printf("%lld\n",a); return ;}
	int tmp=a,minn=INF;
	for(int i=2;i*i<=b;i++)
	{
		if(b%i==0)
		{
			int cnt=0;
			while(b%i==0) cnt++,b/=i;
			int cb=0;
			while(tmp%i==0) tmp/=i,cb++;
			int r=1; for(int j=1;j<=cb-cnt+1;j++) r*=i;
			// printf("%d %d %d\n",cnt,cb,r);
			minn=min(minn,r);
		}
	}
	if(b!=1)
	{
		int cb=0;
		while(tmp%b==0) tmp/=b,cb++;
		int r=1; for(int j=1;j<=cb;j++) r*=b;
		minn=min(minn,r);
	}
	printf("%lld\n",a/minn);
}
signed main()
{
	int T=read(); while(T--) work();
	return 0;
}