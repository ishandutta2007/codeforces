#include<cstdio>
#include<algorithm>
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
template<typename T>inline void rd(T&x){int fl=0,ch;while(ch=getchar(),ch<48||57<ch)fl^=!(ch^45);x=(ch&15);while(ch=getchar(),47<ch&&ch<58)x=x*10+(ch&15);if(fl)x=-x;}
template<typename T>inline void pt(T x){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);}
template<typename T>inline void pt(T x,int ch){pt(x),putchar(ch);}
template<typename T>inline T max(const T&x,const T&y){return x<y?y:x;}
template<typename T>inline T min(const T&x,const T&y){return x<y?x:y;}
const int N=5005;
int n,ans,aa,bb,pp,tr[N<<1];
struct seg{
	int x,l,r;
	bool operator<(const seg&b)const{return x<b.x;}
}a[N];
struct seg2{
	int y,l,r;
}b[N],c[N],p[N];
bool cmp1(const seg2&i,const seg2&j){return i.r<j.r;}
bool cmp2(const seg2&i,const seg2&j){return i.l>j.l;}
void upd(int i,int x){
	i+=N;
	for(;i<(N<<1);i+=i&-i)tr[i]+=x;
}
int qry(int i){
	i+=N;
	int res=0;
	for(;i;i&=i-1)res+=tr[i];
	return res;
}
int qry(int l,int r){
	return qry(r)-qry(l-1);
}
signed main(){
	rd(n);
	rep(i,1,n){
		int x,y,x_,y_;rd(x),rd(y),rd(x_),rd(y_);
		if(x==x_){
			a[++aa]=(seg){x,min(y,y_),max(y,y_)};
		}else{
			b[++bb]=(seg2){y,min(x,x_),max(x,x_)};
			c[bb]=b[bb];
		}
	}
	std::sort(a+1,a+1+aa);
	std::sort(b+1,b+1+bb,cmp1);
	std::sort(c+1,c+1+bb,cmp2);
	rep(i,1,aa){
		pp=0;int he=1;
		rep(j,1,bb){
			if(a[i].l<=b[j].y&&b[j].y<=a[i].r&&b[j].l<=a[i].x&&b[j].r>=a[i].x)
				p[++pp]=b[j],upd(p[pp].y,1);
		}
		rep(j,i+1,aa){
			while(he<=pp&&p[he].r<a[j].x)upd(p[he].y,-1),++he;
			int cnt=qry(max(a[i].l,a[j].l),min(a[i].r,a[j].r));
			ans+=1ll*cnt*(cnt-1)/2;
		}
		while(he<=pp)upd(p[he].y,-1),++he;
	}
	pt(ans,'\n');
	return 0;
}