#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
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
int a[55];
void work()
{
	int n=read();
	int ans=0;
	for(int i=0;;i++)
	{
		if((1LL<<(i+1))-1>=n) {ans=i; break;}
	}
	int sum=(1LL<<(ans+1))-1;
	a[0]=1;
	for(int i=1;i<=ans;i++)
	{
		a[i]=a[i-1]*2;
		while(sum-(1<<(ans-i+1))+1>=n)
		{
			sum=sum-(1<<(ans-i+1))+1;
			a[i]--;
		}
	}
	cout<<ans<<endl;
	for(int i=1;i<=ans;i++) printf("%lld ",a[i]-a[i-1]);
	cout<<"\n";
}
signed main()
{
	int T=read();
	while(T--) work();
	return 0;
}