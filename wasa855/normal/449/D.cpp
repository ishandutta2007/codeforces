#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define fir first
#define sec second
#define mod 1000000007
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
inline int min(int x,int y,int z){return min(x,min(y,z));}
inline int max(int x,int y,int z){return max(x,max(y,z));}
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z){return add(add(x,y),z);}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1LL*x*y%mod;}
inline int mul(int x,int y,int z){return mul(mul(x,y),z);}
#define N 2000005
int a[N],b[N],c[N],pw[N];
int lim=20;
void A(int a[])
{
	for(int i=0;i<lim;i++)
	{
		for(int j=0;j<(1<<lim);j++)
		{
			if(!(j&(1<<i))) a[j]+=a[j^(1<<i)];
		}
	}
}
signed main()
{
	int n=read();
	pw[0]=1; for(int i=1;i<N;i++) pw[i]=mul(pw[i-1],2);
	for(int i=1;i<=n;i++) a[read()]++;
	A(a);
	int ans=0;
	for(int i=0;i<(1<<lim);i++)
	{
		if(__builtin_popcount(i)&1) ans=sub(ans,pw[a[i]]-1);
		else ans=add(ans,pw[a[i]]-1);
	}
	cout<<ans<<endl;
	return 0;
}