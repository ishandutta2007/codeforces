#include<map>
#include<cstdio>
#include<algorithm>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define int long long
template<typename T>inline void rd(T&x){int fl=0,ch;while(ch=getchar(),ch<48||57<ch)fl^=!(ch^45);x=(ch&15);while(ch=getchar(),47<ch&&ch<58)x=x*10+(ch&15);if(fl)x=-x;}
template<typename T>inline void pt(T x){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);}
template<typename T>inline void pt(T x,int ch){pt(x),putchar(ch);}
template<typename T>inline T max(const T&x,const T&y){return x<y?y:x;}
template<typename T>inline T min(const T&x,const T&y){return x<y?x:y;}

const int N=200005;

int n,tot,ans,a[N],mmp[N],t[N];

void upd(int i,int x){
	for(;i<=n;i+=i&-i)t[i]+=x;
}

int qry(int i){
	int res=0;
	for(;i;i&=i-1)res+=t[i];
	return res;
}

struct po{
	int x,y;
	bool operator<(const po&b)const{return y^b.y?y<b.y:x<b.x;}
}p[N];

signed main(){
	rd(n);
	rep(i,1,n){
		rd(p[i].x),rd(p[i].y);
		a[i]=p[i].x;
	}
	std::sort(a+1,a+1+n);
	rep(i,1,n)p[i].x=std::lower_bound(a+1,a+1+n,p[i].x)-a;
	rep(i,1,n)if(!mmp[p[i].x]++)++tot,upd(p[i].x,1);
	std::sort(p+1,p+1+n);
	for(int i=1;i<=n;){
		ans+=1ll*tot*(tot+1)/2;
		int j=i;
		int x=qry(p[j].x-1);
		ans-=1ll*x*(x+1)/2;
		while(j<=n&&p[j].y==p[i].y){
			if(p[j].x!=p[i].x){
				x=qry(p[j].x-1)-qry(p[j-1].x);
				ans-=1ll*x*(x+1)/2;
			}
			++j;
		}
		x=qry(n)-qry(p[j-1].x);
		ans-=1ll*x*(x+1)/2;
		for(int k=i;k<j;++k)if(!--mmp[p[k].x])--tot,upd(p[k].x,-1);
		i=j;
	}
	pt(ans,'\n');
	return 0;
}