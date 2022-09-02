#include<cstdio>
#include<algorithm>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
const int N=2005;
template<typename T>void rd(T&x){int fl=0,ch;while(ch=getchar(),ch<48||57<ch)fl^=!(ch^45);x=(ch&15);while(ch=getchar(),47<ch&&ch<58)x=(x+(x<<2)<<1)+(ch&15);if(fl)x=-x;}
template<typename T>T pt(T x){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);}
template<typename T>T max(const T&x,const T&y){return x<y?y:x;}
template<typename T>T min(const T&x,const T&y){return x<y?x:y;}
int n,m,a[N][N],b[N][N],c[N][N],d[N][N],len1[N],len2[N],ans1[N][N],ans2[N][N];
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)rep(j,1,m)rd(a[i][j]),b[j][i]=a[i][j];
	rep(i,1,n){
		rep(j,1,m)c[i][j]=a[i][j];
		std::sort(a[i]+1,a[i]+1+m);
		len1[i]=std::unique(a[i]+1,a[i]+1+m)-a[i]-1;
		rep(j,1,m)ans1[i][j]=std::lower_bound(a[i]+1,a[i]+1+len1[i],c[i][j])-a[i];
	}
	rep(i,1,m){
		rep(j,1,n)d[i][j]=b[i][j];
		std::sort(b[i]+1,b[i]+1+n);
		len2[i]=std::unique(b[i]+1,b[i]+1+n)-b[i]-1;
		rep(j,1,n)ans2[i][j]=std::lower_bound(b[i]+1,b[i]+1+len2[i],d[i][j])-b[i];
	}
	rep(i,1,n)rep(j,1,m){
		printf("%d%c",max(len1[i],max(len2[j],max(len1[i]-ans1[i][j]+ans2[j][i],len2[j]-ans2[j][i]+ans1[i][j]))),j==m?'\n':' ');
	}
	return 0;
}