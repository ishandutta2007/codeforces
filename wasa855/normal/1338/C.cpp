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
#define N 1000005
bool vis[N];
pair<pii,int> solve(int r)
{
	pair<pii,int> ans; int c=0;
	for(int i=0;;i+=2)
	{
		if(c+(1LL<<i)<r)
		{
			c+=(1LL<<i); continue;
		}
		ans.fir.fir=(1LL<<i)+(r-c)-1LL;
		int x=r-c-1LL;
		// printf("-- %d\n",c);
		ans.fir.sec=(1LL<<(i+1LL));
		for(int j=(1LL<<i);j>=4;j/=4)
		{
			int C=j/4;
			// cout<<"**"<<C<<endl;
			if(x<C) continue;
			if(x<2*C) {ans.fir.sec+=C*2; x-=C; continue;}
			if(x<3*C) {ans.fir.sec+=C*3; x-=C*2; continue;}
			if(x<4*C) {ans.fir.sec+=C; x-=C*3; continue;}
		}
		break;
	}
	ans.sec=ans.fir.fir^ans.fir.sec;
	return ans;
}
void work()
{
	int n=read();
	int r=(n+2)/3;
	pair<pii,int> x=solve(r);
	if(n%3==1) printf("%lld\n",x.fir.fir);
	if(n%3==2) printf("%lld\n",x.fir.sec);
	if(n%3==0) printf("%lld\n",x.sec);
}
signed main()
{
	int T=read();
	while(T--) work();
	return 0;
}