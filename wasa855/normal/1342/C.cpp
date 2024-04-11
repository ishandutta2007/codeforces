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
#define N 40005
int x[N];
void work()
{
	int a=read(),b=read(),Q=read();
	for(int i=0;i<a*b;i++)
	{
		int A=i%a%b,B=i%b%a;
		x[i]=(A!=B);
	}
	int sum=0;
	for(int i=0;i<a*b;i++) sum+=x[i];
	while(Q--)
	{
		int l=read(),r=read();
		int ans=(r/(a*b)-(l+a*b-1)/(a*b))*sum;
		if(l%(a*b)!=0) for(int i=l%(a*b);i<a*b;i++) ans+=x[i];
		for(int i=0;i<=r%(a*b);i++) ans+=x[i];
		printf("%lld ",ans);
	}
	cout<<"\n";
}
signed main()
{
	int T=read();
	while(T--) work();
	return 0;
}