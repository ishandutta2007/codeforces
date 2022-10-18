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
#define N (1<<21)
int a[N],b[N],n;
void fwt(int a[],int typ)
{
	for(int i=1;i<(1<<n);i<<=1)
	{
		for(int j=0;j<(1<<n);j+=(i<<1))
		{
			for(int k=0;k<i;k++)
			{
				if(typ==1) a[i+j+k]+=a[j+k];
				else a[i+j+k]-=a[j+k];
			}
		}
	}
}
signed main()
{
	n=read();
	for(int i=0;i<(1<<n);i++) scanf("%1lld",&a[i]);
	for(int i=0;i<(1<<n);i++) scanf("%1lld",&b[i]);
	for(int i=0;i<(1<<n);i++) a[i]<<=(__builtin_popcount(i)<<1);
	for(int i=0;i<(1<<n);i++) b[i]<<=(__builtin_popcount(i)<<1);
	fwt(a,1),fwt(b,1);
	for(int i=0;i<(1<<n);i++) a[i]*=b[i];
	fwt(a,-1);
	for(int i=0;i<(1<<n);i++) printf("%lld",(a[i]>>(__builtin_popcount(i)<<1))&3);
	return 0;
}