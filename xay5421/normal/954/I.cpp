//by xay5421 2449670833@qq.com
#include<set>
#include<map>
#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
#define debug(...) fprintf(stderr,__VA_ARGS__)
//#define debug(...) ((void)0)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long ll;typedef unsigned long long ull;typedef std::pair<int,int> pii;
template<typename T>void rd(T&x){int f=0,c;while((c=getchar())<48||57<c)f^=!(c^45);x=(c&15);while(47<(c=getchar())&&c<58)x=x*10+(c&15);if(f)x=-x;}
template<typename T>inline void pt(T x){if(x<0)x=-x,putchar('-');if(x>9)pt(x/10);putchar(x%10+48);}
template<typename T>inline void pt(T x,int c){pt(x),putchar(c);}
template<typename T>inline T max(const T&x,const T&y){return x<y?y:x;}
template<typename T>inline T min(const T&x,const T&y){return x<y?x:y;}

typedef std::vector<int> poly;

const int N=125005,P=998244353;

int n,m,ans[N],fa[N][10];
poly A[10],B[10],tmp;
char s[N],t[N];

int find(int*fa,int u){return fa[u]==u?u:fa[u]=find(fa,fa[u]);}

int fpow(int a,int b){
	int res=1;
	for(;b;b>>=1,a=1ll*a*a%P)if(b&1)res=1ll*res*a%P;
	return res;
}

int getlim(int n){
	int x=1;
	while(x<=n)x<<=1;
	return x;
}

void ntt(poly&a,const int&g,const int&lim){
	a.resize(lim);
	for(int i=0,j=0;i<lim;++i){
		if(i<j)std::swap(a[i],a[j]);
		for(int k=lim>>1;(j^=k)<k;k>>=1);
	}
	poly w(lim>>1);w[0]=1;
	for(int i=1;i<lim;i<<=1){
		for(int j=1,wn=fpow(g,(P-1)/(i<<1));j<i;++j)w[j]=1ll*w[j-1]*wn%P;
		for(int j=0;j<lim;j+=i<<1)
			for(int k=0;k<i;++k){
				int x=a[j+k],y=1ll*a[i+j+k]*w[k]%P;
				a[j+k]=(x+y)%P,a[i+j+k]=(x-y+P)%P;
			}
	}
	if(g==332748118)
		for(int i=0,I=fpow(lim,P-2);i<lim;++i)a[i]=1ll*a[i]*I%P;
}

void print(const poly&a){
	for(int i=0;i<SZ(a);++i)debug("%d ",a[i]);debug("\n");
}

signed main(){
	scanf("%s%s",s,t);n=strlen(s),m=strlen(t);
	int lim=getlim(n+m-1);
	rep(c1,0,5){
		A[c1].resize(lim);
		B[c1].resize(lim);
		rep(i,0,n-1)A[c1][i]=(s[i]==c1+'a');
		rep(i,0,m-1)B[c1][m-i-1]=(t[i]==c1+'a');
		ntt(A[c1],3,lim);
		ntt(B[c1],3,lim);
//		print(A[c1]);
//		print(B[c1]);
	}
	rep(i,0,n-m)rep(j,0,5)fa[i][j]=j;
	tmp.resize(lim);
	rep(c1,0,5)rep(c2,0,5)if(c1!=c2){
		rep(i,0,lim-1)tmp[i]=1ll*A[c1][i]*B[c2][i]%P;
		ntt(tmp,332748118,lim);
//		debug("%c => %c:",c1+'a',c2+'a');
//		for(int i=m-1;i<n;++i)debug("%d ",tmp[i]);debug("\n");
		for(int i=0;i<=n-m;++i){
			if(tmp[i+m-1]){
				if(find(fa[i],c1)!=find(fa[i],c2)){
					++ans[i];
					fa[i][find(fa[i],c1)]=find(fa[i],c2);
				}
			}
		}
//		print(tmp);
	}
	rep(i,0,n-m)pt(ans[i],' ');
	return 0;
}