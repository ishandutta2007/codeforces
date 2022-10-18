// Author -- xyr2005 & wasa855

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-(x)))
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

std::mt19937_64 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return !b?a:gcd(b,a%b);}
template <typename _Tp>inline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){a=a<b?b:a;}
template <typename _Tp>inline void chmin(_Tp &a,const _Tp &b){a=a<b?a:b;}
template <typename _Tp>inline void read(_Tp &x)
{
	char ch(getchar());bool f(false);while(!isdigit(ch)) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch)) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	f&&(x=-x);
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
inline int read_str(char *s)
{
	char ch(getchar());while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;*tar++=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *tar++=ch,ch=getchar();
	return *tar=0,tar-s;
}
ll Rnd(ll l,ll r) {return rnd()%(r-l+1)+l;}
const int N=100005;
ll r;
ll ANS;
char s[15];
int cnt;
inline ll ASK(ll x)
{
#ifdef __LOCAL__
	return x<=ANS;
#endif 
	printf("? %lld\n",x),fflush(stdout);
	read_str(s);
	return s[0]=='L';
}
inline int ask(ll x)
{
	++cnt;
/*
#ifdef ONLINE_JUNDGE
	if(cnt>105)
	{
		while((double)clock()/CLOCKS_PER_SEC<4.1);
		exit(0);
	}
#endif
*/
	if(ASK(x))return r+=x,1;
	else return r-=x,0;
}
ll getmid(ll l,ll r,double p) {return l+(r-l)*p;}
int wacnt=0,TOT=0;
//double p[]={0.43,0.43,0.43,0.43};
double p[]={0.36,0.37,0.38,0.39};
void MAIN()
{
	ll L=0,R=1e14;
	r=1,cnt=0;
	while(2*L<R)
	{
		ll mid;
		if(r>=3LL*R)mid=(L+R+1)>>1;
		else mid=min(r,L+(R-L)/3);
		if(ask(mid))L=mid;
		else R=mid-1;
	}
//	printf("%lld %lld %d\n",L,R,::cnt);
//	printf("%lld %lld %d\n",L,R,cnt);
	ll ans=L;
	int strange=0,str2=0;
	while(R-L>=3&&strange<=12&&str2<=12)
	{
		ll mid=getmid(L,R,p[Rnd(0,3)]);
		while(r<mid) ask(ans);
		if(ask(mid)) ans=mid,L=mid+1,strange-=3,str2++;
		else R=mid-1,strange++,str2-=3;
		strange=max(strange,0),str2=max(str2,0);
	}
	while(R-L>=3&&strange&&strange<=1000)
	{
		ll mid=getmid(L,R,0.27);
		while(r<mid) ask(ans),strange++;
		if(ask(mid)) ans=mid,L=mid+1;
		else R=mid-1;
	}
//	while(R-L>=3&&strange>15)
//	{
//		ll mid=getmid(L,R,0.20);
//		while(r<mid) ask(ans);
//		if(ask(mid)) ans=mid,L=mid+1;
//		else R=mid-1;
//	}
	while(R-L>=3&&str2&&str2<=1000)
	{
		ll mid=getmid(L,R,0.48);
		while(r<mid) ask(ans);
		if(ask(mid)) ans=mid,L=mid+1,str2++;
		else R=mid-1;
	}
//	while(R-L>=3&&str2>15)
//	{
//		ll mid=getmid(L,R,0.50);
//		while(r<mid) ask(ans);
//		if(ask(mid)) ans=mid,L=mid+1;
//		else R=mid-1;
//	}
	while(L<=R)
	{
		ll mid=(L+R)/2;
		while(r<mid) ask(ans);
		if(ask(mid)) ans=mid,L=mid+1;
		else R=mid-1;
	}
#ifdef __LOCAL__
	printf("! %lld %lld - ",ans,ANS);
	assert(ans==ANS);
	return ;
#endif
	printf("! %lld\n",ans),fflush(stdout);
}
int main()
{
#ifdef __LOCAL__
	freopen("tmp.out","w",stdout);
	for(int i=1;i<=1000;i++)
	{
		TOT++;
		ANS=Rnd(3e13,4e13);
//		ANS=83122211361963;
		MAIN();
		printf("%d\n",cnt);
		if(cnt>105) wacnt++;
	}
	fprintf(stderr,"%d / %d\n",wacnt,TOT);
	return 0;
#endif
	int _;read(_);
	while(_--)MAIN();
	return 0;
}