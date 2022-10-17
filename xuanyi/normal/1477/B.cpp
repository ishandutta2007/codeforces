// author: xay5421
// created: Thu Jan 28 22:42:38 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define int long long
#define LL long long
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define X first
#define Y second
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef pair<int,int>PII;
typedef vector<int>VI;
typedef vector<PII>VII;
template<typename T>void umin(T&x,const T&y){if(y<x)x=y;}
template<typename T>void umax(T&x,const T&y){if(x<y)x=y;}
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=200005;
int T,n,q,l[N],r[N],fa[N];
char s[N],t[N],tt[N];
int len[N*4],sum[N*4],tg[N*4];
void pst(int k1,int k2){
	tg[k1]=k2,sum[k1]=k2*len[k1];
}
void psd(int k1){
	if(tg[k1]!=-1){
		pst(k1*2,tg[k1]);
		pst(k1*2+1,tg[k1]);
		tg[k1]=-1;
	}
}
void upd(int k1){
	sum[k1]=sum[k1*2]+sum[k1*2+1];
}
void bud(int k1,int k2,int k3){
	tg[k1]=-1,len[k1]=k3-k2+1;
	if(k2==k3){
		sum[k1]=t[k2]=='1';
		return;
	}
	int mid=(k2+k3)>>1;
	bud(k1*2,k2,mid),bud(k1*2+1,mid+1,k3);
	upd(k1);
}
int ask(int k1,int k2,int k3,int k4,int k5){
	if(k2>k5||k3<k4)return 0;
	if(k4<=k2&&k3<=k5)return sum[k1];
	psd(k1);
	int mid=(k2+k3)>>1;
	return ask(k1*2,k2,mid,k4,k5)+ask(k1*2+1,mid+1,k3,k4,k5);
}
void down(int k1,int k2,int k3){
	if(k2==k3){
		tt[k2]=sum[k1]+'0';
		return;
	}
	psd(k1);
	int mid=(k2+k3)>>1;
	down(k1*2,k2,mid),down(k1*2+1,mid+1,k3);
}
void mdf(int k1,int k2,int k3,int k4,int k5,int k6){
	if(k2>k5||k3<k4)return;
	if(k4<=k2&&k3<=k5){
		pst(k1,k6);
		return;
	}
	psd(k1);
	int mid=(k2+k3)>>1;
	mdf(k1*2,k2,mid,k4,k5,k6),mdf(k1*2+1,mid+1,k3,k4,k5,k6);
	upd(k1);
}
signed main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(T);
	while(T--){
		rd(n),rd(q);
		scanf("%s%s",s+1,t+1);
		bud(1,1,n);
		rep(i,1,q){
			rd(l[i]),rd(r[i]);
		}
		bool flg=1;
		per(i,q,1){
			int x=ask(1,1,n,l[i],r[i]);
			if(x<=(r[i]-l[i])/2){
				mdf(1,1,n,l[i],r[i],0);
			}else if(r[i]-l[i]+1-x<=(r[i]-l[i])/2){
				mdf(1,1,n,l[i],r[i],1);
			}else{
				flg=0;
				break;
			}
		}
		down(1,1,n);
		if(flg)rep(i,1,n)flg&=s[i]==tt[i];
		puts(flg?"YES":"NO");
	}
	return 0;
}