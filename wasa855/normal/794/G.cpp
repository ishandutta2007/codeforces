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
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z){return add(add(x,y),z);}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1LL*x*y%mod;}
inline int mul(int x,int y,int z){return mul(mul(x,y),z);}
#define N 600005
int fac[N],inv[N],pinv[N],pw[N],p[N],vis[N],mu[N],cnt;
void init()
{
	fac[0]=1; for(int i=1;i<N;i++) fac[i]=mul(fac[i-1],i);
	inv[0]=inv[1]=1; for(int i=2;i<N;i++) inv[i]=mul(mod-mod/i,inv[mod%i]);
	pinv[0]=1; for(int i=1;i<N;i++) pinv[i]=mul(pinv[i-1],inv[i]);
	pw[0]=1; for(int i=1;i<N;i++) pw[i]=add(pw[i-1],pw[i-1]);
	mu[1]=1;
	for(int i=2;i<N;i++)
	{
		if(!vis[i])
		{
			p[++cnt]=i;
			mu[i]=-1;
		}
		for(int j=1;j<=cnt;j++)
		{
			if(i*p[j]>=N) break;
			vis[i*p[j]]=1;
			mu[i*p[j]]=-mu[i];
			if(i%p[j]==0)
			{
				mu[i*p[j]]=0;
				break;
			}
		}
	}
	for(int i=1;i<N;i++) if(mu[i]==-1) mu[i]+=mod;
}
int C(int x,int y){return x>=y?mul(fac[x],pinv[x-y],pinv[y]):0;}
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
char s[N],t[N];
int sa,sb,sc,ta,tb,tc,x,y,n;
int _R[N],_QAQ;
int Calc()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j+=i) _R[j]=add(_R[j],mul(pw[j/i],mu[i]));
	}
	int Ans=0;
	for(int i=1;i<=n;i++) Ans=add(Ans,mul(n/i,n/i,_R[i]));
	return Ans;
}
int f(int x,int y)
{
	if(!x&&!y) return _QAQ;
	if(1LL*x*y>=0) return 0;
	x=abs(x),y=abs(y);
	if(x>y) swap(x,y);
	int g=__gcd(x,y);
	int K=y/g;
	return sub(pw[n/K+1],2);
}
signed main()
{
	init();	
	scanf("%s%s",s+1,t+1); n=read(); _QAQ=Calc();
	// cout<<_QAQ<<endl;
	x=strlen(s+1),y=strlen(t+1);
	for(int i=1;i<=x;i++)
	{
		if(s[i]=='A') sa++;
		else if(s[i]=='B') sb++;
		else sc++;
	}
	for(int i=1;i<=y;i++)
	{
		if(t[i]=='A') sa--;
		else if(t[i]=='B') sb--;
		else tc++;
	}
	bool ok=1; int ct=0;
	int ans=0;
	if(x==y)
	{
		for(int i=1;i<=x;i++)
		{
			if(s[i]=='?'&&t[i]=='?') ct++;
			else if(s[i]!='?'&&t[i]!='?'&&s[i]!=t[i]) ok=0;
			// if(s[i]=='?'&&t[i]=='A') ca++;
		}
		if(!ok) ct=0;
		if(ok) ans=add(ans,mul(pw[ct],pw[n+1]-2,pw[n+1]-2));
	}
	else ok=0;
	// cout<<ans<<endl;
	sb+=sc-tc;
	for(int i=-tc;i<=sc;i++)
	{
		int R=f(sa+i,sb-i),sum=C(sc+tc,sc-i);
		if(sa+i==0&&sb-i==0&&ok) sum=sub(sum,pw[ct]);
		// printf("%d : %d %d : %d %d\n",i,sa+i,sb-i,R,sum);
		ans=add(ans,mul(R,sum));
	}
	cout<<ans<<endl;
	return 0;
}