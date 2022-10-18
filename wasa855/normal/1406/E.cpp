// Author -- xyr2005 & wasa855
 
#include<bits/stdc++.h>
 
#define lowbit(x) ((x)&(-(x)))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define SZ(x) ((int)x.size())
#define mkpr std::make_pair
#define pb push_back
 
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef std::pair<int,int> pi;
typedef std::pair<ll,ll> pl;
using std::min;
using std::max;
 
const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x3f3f3f3f3f3f3f3f;
 
Finline uint rnd(){static uint seed=416;return seed+=0x71dad4bfu,seed^=seed>>5,seed+=0xc6f74d88u,seed^=seed<<17,seed+=0x25e6561u,seed^=seed>>13;}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>Finline void read(_Tp &x)
{
	char ch(getchar());bool f(false);while(!isdigit(ch)) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch)) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	f&&(x=-x);
}
template <typename _Tp,typename... Args>Finline void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp,typename... Args>Finline _Tp min(const _Tp &a,const _Tp &b,const Args &...args){return a<b?min(a,args...):min(b,args...);}
template <typename _Tp,typename... Args>Finline _Tp max(const _Tp &a,const _Tp &b,const Args &...args){return a<b?max(b,args...):max(a,args...);}
Finline int read_str(char *s)
{
	char ch(getchar());while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;*tar=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}
 
const int N=100005;
const int MAXN=100001;
bool pr[MAXN];
int p[MAXN],pos;
void sieve()
{
	for(int i=2;i<MAXN;++i)
	{
		if(!pr[i]) p[++pos]=i;
		for(int j=1;j<=pos&&i*p[j]<MAXN;++j)
		{
			pr[i*p[j]]=true;
			if(!(i%p[j])) break;
		}
	}
}
int n,cnt;
int Cnt;
int A(int x)
{
	if(x>n) return 0;
	Cnt++;
	assert(Cnt<=1e4);
	printf("A %d\n",x);
	fflush(stdout);
	read(x);return x;
}
int B(int x)
{
	if(x>n) return 0;
	Cnt++;
	assert(Cnt<=1e4);
	printf("B %d\n",x);
	fflush(stdout);
	read(x);return x;
}
bool vis[N];
int doit(int p)
{
    int ans=0;
    for(int i=p;i<=n;i+=p)
    {
        if(!vis[i]) ans++,vis[i]=1;
    }
    return ans;
}
int main()
{
	sieve();fprintf(stderr,"%d\n",pos);
	read(n);
	int cnt=A(1);
	int l=66;
	int ans=1;
	bool ok=0;
	while(l<=pos)
	{
		int mid=(l+pos)>>1;
		int orig=cnt;
		for(int i=l;i<=mid;i++) orig-=doit(p[i]);
		for(int i=l;i<=mid;++i) B(p[i]);
		cnt=A(1);
		if(orig!=cnt)
		{
			for(int i=l;i<=mid;++i)
			{
				if(A(p[i]))
				{
					ans=p[i];
					ok=1;
					break;
				}
			}
		}
		if(ok) break;
		l=mid+1;
	}
	for(int i=1;i<=65;++i)
	{
		B(p[i]);
		int tmp=p[i];
		while(A(tmp)) tmp*=p[i],ans*=p[i];
	}
	printf("C %d\n",ans);
	fflush(stdout);
	return 0;
}