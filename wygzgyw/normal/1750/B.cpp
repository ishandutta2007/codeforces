// wygzgyw
#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
template <typename T> void write(T t) {
	if (t<0) { putchar('-'); write(-t); return; }
	if (t>9) write(t/10);
	putchar('0'+t%10);
}
template <typename T> void writeln(T t) { write(t); puts(""); }
#define MP make_pair
typedef long long ll;
const int maxn=(2e5)+10;
int T,n;
char s[maxn];

int main() {
	read(T);
	while (T--) {
		read(n);
		scanf("%s",s+1);
		int c0=0,c1=0;
		for (int i=1;i<=n;i++) if (s[i]=='0') c0++; else c1++;
		if (c0==n||c1==n) printf("%lld\n",(ll)n*n);
		else {
			ll ans=(ll)c0*c1;
			int len=0;
			for (int i=1;i<=n;i++) {
				if (i>1&&s[i]==s[i-1]) len++;
				else ans=max(ans,(ll)len*len),len=1;
			}
			ans=max(ans,(ll)len*len);
			printf("%lld\n",ans);
		}
	}
	return 0;
}