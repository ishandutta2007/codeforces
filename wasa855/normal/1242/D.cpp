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
int k;
inline int get(){return k*(k+1)/2;}
int find(int id)
{
	if(!id) return get();
	int a=id/k,x=find(a),t=id-a*k;
	int A=a*(k*k+1)+t*k;
	int ans=A*k+get(),R=x-A;
	if(R<=0) ans+=k;
	else if(R<=k) ans+=k-R+1;
	return ans;
}
void work()
{
	int n=read(); k=read();
	int bel=(n-1)/(k*k+1),x=find(bel);
	// cout<<x<<endl;
	if(n==x)
	{
		printf("%lld\n",(bel+1)*(k+1));
	}
	else
	{
		int sum=n-bel-(n>x),ans=bel*k*k+(n-1)%(k*k+1)+1-(n>x);
		// printf("%lld %lld\n",sum,ans);
		ans+=(sum-1)/k;
		printf("%lld\n",ans);
	}
}
signed main()
{
	int T=read(); while(T--) work();
	return 0;
}