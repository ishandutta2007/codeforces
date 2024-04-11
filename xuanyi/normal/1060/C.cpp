#include <cstdio>
#include <cstring>
typedef long long ll;

const int MAXN=2005;

int n,m,X,ans,mn[MAXN],mn2[MAXN];
int a[MAXN],b[MAXN]; ll sa[MAXN],sb[MAXN];

template <typename T>
inline void read(T &x){
	int ch,fl=0;
	while (ch=getchar(),ch<48 || 57<ch) fl^=!(ch^45); x=(ch&15);
	while (ch=getchar(),47<ch && ch<58) x=(x<<1)+(x<<3)+(ch&15);
	if (fl) x=-x;
}

int main(){
	memset(mn,63,sizeof(mn));
	memset(mn2,63,sizeof(mn2));
	register int i,j;
	read(n),read(m);
	for (i=1;i<=n;++i) read(a[i]),sa[i]=sa[i-1]+a[i];
	for (i=1;i<=m;++i) read(b[i]),sb[i]=sb[i-1]+b[i];
	for (i=1;i<=n;++i)
		for (j=i;j<=n;++j){
			if (sa[j]-sa[i-1]<mn[j-i+1]) mn[j-i+1]=sa[j]-sa[i-1];
		}
	for (i=1;i<=m;++i)
		for (j=i;j<=m;++j) 
			if (sb[j]-sb[i-1]<mn2[j-i+1]) mn2[j-i+1]=sb[j]-sb[i-1];
	read(X);
	for (i=1;i<=n;++i)
		for (j=1;j<=m;++j)
			if ((ll)mn[i]*mn2[j]<=X && ans<i*j)
				ans=i*j;
	printf("%d\n",ans);
	return 0;
}