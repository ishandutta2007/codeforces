#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN=100005;

int n,m,ans;
int a[MAXN],s[MAXN],s2[MAXN];

template <typename T>
inline void read(T &x){
	int ch,fl=0;
	while (ch=getchar(),ch<48 || 57<ch) fl^=!(ch^45); x=(ch&15);
	while (ch=getchar(),47<ch && ch<58) x=(x<<1)+(x<<3)+(ch&15);
	if (fl) x=-x;
}

template <typename T>
inline void print(T x){
	if (x<0) x=-x,putchar('-');
	if (x>9) print(x/10);
	putchar(x%10+48);
}

int main(){
	read(n),read(m); ++n;
	for (int i=2;i<=n;++i) read(a[i]); a[++n]=m;
	for (int i=1;i<n;++i) a[i]=a[i+1]-a[i]; a[n--]=0;
	for (int i=1;i<=n;++i){
		s[i]=s[i-1];
		if (i&1) s[i]+=a[i],ans+=a[i];
	}
	for (int i=n;i>=1;--i){
		s2[i]=s2[i+1];
		if (!(i&1)) s2[i]+=a[i];
	}
	for (int i=1;i<=n;++i) if (a[i]!=1){
		if (i&1){
			ans=max(ans,s[i]-1+s2[i+1]);
		} else{
			ans=max(ans,s[i-1]+s2[i]-1);
		}
	}
	printf("%d\n",ans);
	return 0;
}