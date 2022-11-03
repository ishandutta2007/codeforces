#include<queue>
#include<ctime>
#include<vector>
#include<cstdio>
#include<cstring>
#include<memory.h>
#include<map>
#include<ctime>
#include<algorithm>
#define ll long long
#define For(i,j,k)  for(ll i=j;i<=k;++i)
#define FOr(i,j,k)  for(ll i=j;i>=k;--i)
#define F first
#define S i
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; }
inline void wrote(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) wrote(x/10);   putchar(x%10+'0');  }
inline void writeln(ll x){ wrote(x);   puts("");   }
const ll N=150;
ll answ,n;
ll dp(ll one,ll la,ll lb,ll remain){
//	printf("%lld %lld %lld %lld\n",one,la,lb,remain);
	static ll f[N][2],las[N][2];
	memset(f,0,sizeof f);
	f[0][0]=1;
	for(ll i=0;(1ll<<i)<=remain;++i){
		memcpy(las,f,sizeof f);
		memset(f,0,sizeof f);
		For(ca,0,(i<la))	For(cb,0,(i<lb))	For(re,0,1)//ca,cb,re
		{
			ll now=ca+cb+re;
			if ((now&1)!=((remain>>i)&1))	continue;
			For(al,0,one-ca-cb)	f[al+ca+cb][now>>1]+=las[al][re];
		}
	}return f[one][0];
}
int main(){
//	freopen("a.in","r",stdin);
	n=read();
	For(len_a,0,58)	For(len_b,0,58){
		ll t=(1ll<<len_a+1)+(1ll<<len_b+1)-3;
		ll lca=n/t;	if (!lca)	continue;//lca
		ll res=n-lca*t-((1ll<<len_b)-1);//
		For(one,0,len_a+len_b){
			ll remain=res+one;//1
			if (remain<0||remain%2==1)	continue;
			remain>>=1;
			answ+=dp(one,max(len_a-1,0LL),max(len_b-1,0LL),remain);
		}
	}writeln(answ);
}