// author: xay5421
// created: Tue Aug 24 23:28:10 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long LL;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int P=998244353,INF=0X3F3F3F3F;
int ad(int k1,int k2){return k1+=k2-P,k1+=k1>>31&P;}
int su(int k1,int k2){return k1-=k2,k1+=k1>>31&P;}
int mu(int k1,int k2){return 1LL*k1*k2%P;}
void uad(int&k1,int k2){k1+=k2-P,k1+=k1>>31&P;}
void usu(int&k1,int k2){k1-=k2,k1+=k1>>31&P;}
template<typename... T>int ad(int k1,T... k2){return ad(k1,ad(k2...));}
template<typename... T>int su(int k1,T... k2){return su(k1,ad(k2...));}
template<typename... T>int mu(int k1,T... k2){return mu(k1,mu(k2...));}
template<typename... T>void uad(int&k1,T... k2){return uad(k1,ad(k2...));}
template<typename... T>void usu(int&k1,T... k2){return usu(k1,ad(k2...));}
int po(int k1,int k2){
	int k3=1;
	for(;k2;k2>>=1,k1=mu(k1,k1))if(k2&1)k3=mu(k3,k1);
	return k3;
}
const int N=200005;
namespace FHQ{
	int rnd[N],val[N],sz[N],ch[N][2],ind,tg[N];
	inline int brand(){
		return((rand()&0x7fff)<<16)+((rand()&0x7fff)<<1)+(rand()&1);
	}
	inline int newnode(int _v){
		rnd[++ind]=brand(),sz[ind]=1,val[ind]=_v;return ind;
	}
	inline void update(int u){
		sz[u]=sz[ch[u][0]]+sz[ch[u][1]]+1;
	}
	void pst(int u,int x){
		if(u){
			tg[u]+=x;
			val[u]+=x;
		}
	}
	void psd(int u){
		if(tg[u]){
			if(ch[u][0])pst(ch[u][0],tg[u]);
			if(ch[u][1])pst(ch[u][1],tg[u]);
			tg[u]=0;
		}
	}
	void clear(){
		rep(i,1,ind)rnd[i]=val[i]=sz[i]=ch[i][0]=ch[i][1]=0;
		ind=0;
	}
	int merge(int a,int b){
		if(!a||!b)return a+b;
		psd(a),psd(b);
		if(rnd[a]<rnd[b]){
			ch[a][1]=merge(ch[a][1],b);
			update(a);
			return a;
		}else{
			ch[b][0]=merge(a,ch[b][0]);
			update(b);
			return b;
		}
	}
	void splitv(int a,int b,int&l,int&r){
		if(!a){l=r=0;return;}
		psd(a);
		if(val[a]<=b)l=a,splitv(ch[a][1],b,ch[a][1],r);
		else r=a,splitv(ch[a][0],b,l,ch[a][0]);
		update(a);
	}
	void splits(int a,int b,int&l,int&r){
		if(!a){l=r=0;return;}
		psd(a);
		if(b<=sz[ch[a][0]])r=a,splits(ch[a][0],b,l,ch[a][0]);
		else l=a,splits(ch[a][1],b-sz[ch[a][0]]-1,ch[a][1],r);
		update(a);
	}
	bool have(int u,int x){
		if(!u)return 0;
		psd(u);
		if(val[u]==x){
			return 1;
		}if(x<val[u]){
			return have(ch[u][0],x);
		}
		else{
			return have(ch[u][1],x);
		}
	}
};
using namespace FHQ;
int T,n,m,x[N],y[N],rt,fac[N*2],inv[N*2],ifac[N*2];
int C(int k1,int k2){
	if(k1<0||k2<0||k1-k2<0)return 0;
	return 1LL*fac[k1]*ifac[k2]%P*ifac[k1-k2]%P;
}
void out(int u){
	if(!u)return;
	psd(u);
	out(ch[u][0]);
	D("%d ",val[u]);
	out(ch[u][1]);
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	fac[0]=fac[1]=inv[0]=inv[1]=ifac[0]=ifac[1]=1;
	for(int i=2;i<N*2;++i)fac[i]=1LL*fac[i-1]*i%P,inv[i]=1LL*(P-P/i)*inv[P%i]%P,ifac[i]=1LL*ifac[i-1]*inv[i]%P;
	rd(T);
	rep(_,1,T){
		rd(n),rd(m);
		FHQ::clear();
		rt=0;
		int mn=INF;
		rep(i,1,m){
			rd(x[i]),rd(y[i]);
			if(y[i]<mn){
				pst(rt,1);
				rt=merge(newnode(y[i]+1),rt);
				mn=y[i]+1;
			}else{
				if(have(rt,y[i])){
					int k1,k2;
					splitv(rt,y[i]-1,k1,k2);
					pst(k2,1);
					rt=merge(k1,k2);
					if(mn>=y[i])++mn;
				}else{
					int k1,k2;
					splitv(rt,y[i]-1,k1,k2);
					pst(k2,1);
					rt=merge(k1,merge(newnode(y[i]+1),k2));
					if(mn>=y[i])++mn;
					mn=min(mn,y[i]+1);
				}
			}
			//out(rt),D("\n");
		}
		int tot=n-sz[rt];
		printf("%d\n",C(n+tot-1,n));
	}
	return 0;
}