#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN=1005;

int n,cnt,f[MAXN],a[MAXN],b[MAXN],sta[MAXN],ans[MAXN];

template <typename T>
inline void read(T &x){
	int ch,fl=0;
	while (ch=getchar(),ch<48 || 57<ch) fl^=!(ch^45); x=(ch&15);
	while (ch=getchar(),47<ch && ch<58) x=(x<<1)+(x<<3)+(ch&15);
	if (fl) x=-x;
}

inline bool cmp(const int &a,const int &b){
	return b<a;
}

int main(){
	read(n);
	for (int i=1;i<n;++i){
		read(a[i]),read(b[i]);
		if (b[i]<a[i]) swap(a[i],b[i]); 
	}
	for (int i=1;i<n;++i)
		if (b[i]!=n)
			return puts("NO"),0;
	for (int i=1;i<n;++i)
		f[a[i]]=1;
	for (int i=1;i<n;++i)
		if (!f[i]) sta[++sta[0]]=i;
	sort(a+1,a+1+n,cmp);
	for (int i=2,lst=1;i<=n;++i)
		if (a[i]!=a[i-1]){
			int j=i-lst-1;
			if (sta[0]<j){
				return puts("NO"),0;
			}
			for (int k=1;k<=j;++k){
				if (sta[sta[0]]>a[i-1]){
					return puts("NO"),0;
				}
				ans[++ans[0]]=sta[sta[0]--];
			}
			ans[++ans[0]]=a[i-1];
			lst=i;
		}
	puts("YES");
	printf("%d %d\n",n,ans[1]);
	for (int i=2;i<=ans[0];++i) printf("%d %d\n",ans[i-1],ans[i]);
	return 0;
}