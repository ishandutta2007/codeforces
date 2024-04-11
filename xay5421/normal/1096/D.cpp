#include <cstdio>
#include <cstring>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
typedef long long ll;
const int MOD=998244353;

template <typename T>
void read(T &x){
	int fl=0,ch;
	while (ch=getchar(),ch<48||57<ch) fl^=!(ch^45); x=(ch&15);
	while (ch=getchar(),47<ch&&ch<58) x=(x+(x<<2)<<1)+(ch&15);
	if (fl) x=-x;
}

template <typename T>
void print(T x){
	if (x<0) x=-x,putchar('-');
	if (x>9) print(x/10);
	putchar(x%10+48);
}

template <typename T>
void print(T x,int ch){
	print(x),putchar(ch);
}

template <typename T>
T max(const T &x,const T &y){return x<y?y:x;}

template <typename T>
T min(const T &x,const T &y){return x<y?x:y;}

#define int long long

const int N=100005;
const char ss[]=" hard";

int n,m,a[N],f[N][5],ans;
char s[N];

signed main(){
	read(n);
	memset(f,63,sizeof(f)); ans=f[0][0],f[0][0]=0;
	scanf("%s",s+1);
	rep (i,1,n) read(a[i]);
	rep (i,1,n){
		rep (j,0,3){
			if (s[i]==ss[j]) f[i][j]=min(f[i-1][j],f[i-1][j-1]);
			if (s[i]!=ss[j+1]&&f[i-1][j]<f[i][j]) f[i][j]=f[i-1][j];
			if (s[i]==ss[j+1]&&f[i-1][j]+a[i]<f[i][j]) f[i][j]=f[i-1][j]+a[i];
		}
	}
	rep (j,0,3) if (f[n][j]<ans) ans=f[n][j];
	print(ans,'\n');
	return 0;
}