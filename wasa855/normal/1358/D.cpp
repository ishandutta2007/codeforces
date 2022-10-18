#include<bits/stdc++.h>
using namespace std;
#define pb push_back
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
inline int min(int x,int y,int z){return min(x,min(y,z));}
inline int max(int x,int y,int z){return max(x,max(y,z));}
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z){return add(add(x,y),z);}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1LL*x*y%mod;}
inline int mul(int x,int y,int z){return mul(mul(x,y),z);}
#define N 400005
int a[N],sum[N];
int sqr(int x){return x*(x+1)/2;}
signed main()
{
	int n=read(),x=read(),ans=0;
	for(int i=1;i<=n;i++) a[i]=a[i+n]=read();
	n<<=1;
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+sqr(a[i]);
	for(int i=1;i<=n;i++)
	{
		if(a[i]>=x) ans=max(ans,sqr(a[i])-sqr(a[i]-x));
	}
	int r=1,cur=a[1];
	for(int i=1;i<=n;i++)
	{
		cur-=a[i];
		while(r<n&&cur+a[r+1]<x)
		{
			if(cur+a[i]>=x)
			{
				int tmp=x-cur;
				ans=max(ans,sum[r]-sum[i]+sqr(a[i])-sqr(a[i]-tmp));
			}
			cur+=a[++r];
		}
		if(cur+a[i]<x) continue;
		int tmp=x-cur;
		// printf("%d %d %d %d\n",i,cur,tmp,r);
		ans=max(ans,sum[r]-sum[i]+sqr(a[i])-sqr(a[i]-tmp));
	}
	cout<<ans<<endl;
	return 0;
}