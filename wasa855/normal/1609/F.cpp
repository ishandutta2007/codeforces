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
const int BUF_SIZ=1<<16;
char obuf[BUF_SIZ],*oS=obuf,*oT=oS+BUF_SIZ;
#define flush() (fwrite(obuf,1,oS-obuf,stdout),oS=obuf,void())
#define putchar(x) (*oS++=(x),oS==oT?flush():void())
void _print(int u){if(u>9)_print(u/10);putchar(u%10+48);}
inline void print(int u){_print(u),putchar(' ');}
char ibuf[BUF_SIZ],*iS=ibuf,*iT=ibuf;
#define getchar() (iS==iT&&(iT=(iS=ibuf)+fread(ibuf,1,BUF_SIZ,stdin)),iS==iT?EOF:*iS++)
inline ll read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	ll ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%d%c",x[i]," \n"[i==(int)x.size()-1]);}
#define N 1000005
ll a[N];
int pop[N],st1[N],pre[N],tp1,st2[N],suf[N],tp2,n;
struct SMT
{
	int a[N],b[N]; 
	void build(int u,int l,int r)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
	}
	void update(int u,int l,int r,int L,int R,int v)
	{
		for ( int i = L; i <= n; i += i & -i) a[i] += v, b[i] += (L - 1) * v;
		for ( int i = R + 1; i <= n; i += i & -i) a[i] -= v, b[i] -= R * v;
	}
	int query(int u,int l,int r,int L,int R)
	{
		int ans = 0; 
		for ( int i = R; i; i -= i & -i) ans += 1ll * a[i] * R - b[i];
		for ( int i = L - 1; i; i -= i & -i) ans -= a[i] * (L - 1) - b[i]; 
		return ans;
	}
}smt1,smt2;
signed main()
{
	cin>>n; for(int i=1;i<=n;i++) a[i]=read(),pop[i]=__builtin_popcountll(a[i]);
	ll ans=0,cur=0;
	for(int st=0;st<=60;st++)
	{
		smt1.build(1,1,n),smt2.build(1,1,n);
		tp1=tp2=0; cur=0;
		for(int i=1;i<=n;i++)
		{
			while(tp1&&a[i]<a[st1[tp1]])
			{
				if(pop[st1[tp1]]==st) smt1.update(1,1,n,st1[tp1-1]+1,st1[tp1],-1),cur-=smt2.query(1,1,n,st1[tp1-1]+1,st1[tp1]);
				tp1--;
			}
			if(pop[i]==st) smt1.update(1,1,n,st1[tp1]+1,i,1),cur+=smt2.query(1,1,n,st1[tp1]+1,i);
			st1[++tp1]=i;
			while(tp2&&a[i]>a[st2[tp2]])
			{
				if(pop[st2[tp2]]==st) smt2.update(1,1,n,st2[tp2-1]+1,st2[tp2],-1),cur-=smt1.query(1,1,n,st2[tp2-1]+1,st2[tp2]);
				tp2--;
			}
			if(pop[i]==st) smt2.update(1,1,n,st2[tp2]+1,i,1),cur+=smt1.query(1,1,n,st2[tp2]+1,i);
			st2[++tp2]=i;
			ans+=cur;
			// printf("^ %d %d %d\n",i,cur,ans);
		}
		// cout<<ans<<endl;
	}
	cout<<ans<<endl;
	return 0;
}