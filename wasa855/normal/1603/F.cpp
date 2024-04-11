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
#define ll long long
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
inline int add(int x,int y) {return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z) {return add(add(x,y),z);}
inline int sub(int x,int y) {return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y) {return 1LL*x*y%mod;}
inline int mul(int x,int y,int z) {return mul(mul(x,y),z);}
int qpow(int x,int y)
{
	int ans=1;
	while(y)
	{
		if(y&1) ans=mul(ans,x);
		x=mul(x,x);
		y>>=1;
	}
	return ans;
}
int Inv(int x){return qpow(x,mod-2);}
#define N 10000005
int pw[N],res[N],co[N];
void work()
{
	int n=read(),k=read(),x=read();
	if(x==0)
	{
		if(n>k) printf("0\n");
		else
		{
			int ans=1;
			for(int i=0;i<n;i++) ans=mul(ans,sub(pw[k],pw[i]));
			printf("%d\n",ans);
		}
	}
	else
	{
		int ans=0,c=qpow(2,n);
		res[0]=pw[k-1]-1; for(int i=1;i<k;i++) res[i]=mul(res[i-1],pw[k-i-1]-1);
		co[0]=1; for(int i=1;i<=k;i++) co[i]=mul(co[i-1],c);
		for(int i=0;i<k;i++)
		{
			int r=mul(co[k-i-1],i?res[i-1]:1,pw[k-i-1]);
			// printf("^ %d %d %d\n",co[k-i-1],i?res[i-1]:1,pw[k-i-1]);
			if(i&1) ans=sub(ans,r);
			else ans=add(ans,r);
		}
		printf("%d\n",ans);
	}
}
signed main()
{
	pw[0]=1; for(int i=1;i<N;i++) pw[i]=add(pw[i-1],pw[i-1]);
	int T=read(); while(T--) work();
	return 0;
}