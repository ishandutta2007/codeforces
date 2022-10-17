#pragma GCC optimize(3)
#include<map>
#include<cstdio>
#include<algorithm>
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
template<typename T>inline void rd(T&x){int fl=0,ch;while(ch=getchar(),ch<48||57<ch)fl^=!(ch^45);x=(ch&15);while(ch=getchar(),47<ch&&ch<58)x=x*10+(ch&15);if(fl)x=-x;}
template<typename T>inline void pt(T x){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);}
template<typename T>inline void pt(T x,int ch){pt(x),putchar(ch);}
template<typename T>inline T max(const T&x,const T&y){return x<y?y:x;}
template<typename T>inline T min(const T&x,const T&y){return x<y?x:y;}
const int N=300005;
struct po{
	int x,y;
	po operator-(const po&b)const{return(po){x-b.x,y-b.y};}
	bool operator<(const po&b)const{return x<b.x||(x==b.x&&y<b.y);}
}a[N],t[N];
int n,len,res,tot,B,ans[N],bel[N],pre[N],nxt[N],le[N],ri[N],l=1,r;std::map<po,int>mmp;
int gcd(int a,int b){
	if(a<0)a=-a;if(b<0)b=-b;
	if(!a)return b;if(!b)return a;
	while(a^=b^=a^=b%=a,a);return b;
}
struct ASK{
	int l,r,id;
	bool operator<(const ASK&b)const{return bel[l]^bel[b.l]?l<b.l:bel[l]&1?r<b.r:r>b.r;} 
}q[N];
bool IN(int x){if(!x)return 0;return l<=x&&x<=r;}
bool OU(int x){return !IN(x);}
void ins(int x){
	if(OU(pre[x])&&OU(nxt[x]))++res;
}
void del(int x){
	if(OU(pre[x])&&OU(nxt[x]))--res;
}
signed main(){
	rd(n);
	rep(i,1,n){
		int k;rd(k);
		rep(j,1,k)rd(t[j].x),rd(t[j].y);
		t[k+1]=t[1];
		rep(j,1,k){
			a[++len]=t[j+1]-t[j];
		}
		le[i]=ri[i-1]+1;
		ri[i]=len;
	}
	B=sqrt(len)+1;
	rep(i,1,len)bel[i]=(i-1)/B+1;
	rep(i,1,len){
		po tp=a[i];int gc=gcd(tp.x,tp.y);
		tp.x/=gc,tp.y/=gc;
		if(!mmp[tp])mmp[tp]=i;
		else pre[i]=mmp[tp],nxt[mmp[tp]]=i,mmp[tp]=i;
	}
	int T;
	rd(T);
	rep(i,1,T){
		int l,r;rd(l),rd(r);
		l=le[l],r=ri[r];
		q[++tot]=(ASK){l,r,i};
	}
	std::sort(q+1,q+1+tot);
	rep(i,1,T){
		while(r<q[i].r)ins(++r);
		while(l>q[i].l)ins(--l);
		while(r>q[i].r)del(r--);
		while(l<q[i].l)del(l++);
		ans[q[i].id]=res;
	}
	rep(i,1,T)pt(ans[i],'\n');
	return 0;
}