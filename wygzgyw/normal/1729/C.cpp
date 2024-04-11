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
const int maxn=(2e5)+10;
int T,n;
char s[maxn];
int d[maxn],tot;
bool cmp(int x,int y) { return s[x]<s[y]; }
int main() {
	read(T); while (T--) {
		scanf("%s",s+1); n=strlen(s+1);
		if (s[1]>s[n]) for (int i=1;i<=n;i++) s[i]=(25-(s[i]-'a'))+'a';
		tot=0;
		for (int i=2;i<n;i++) if (s[i]>=s[1]&&s[i]<=s[n]) d[++tot]=i;
		sort(d+1,d+tot+1,cmp);
		printf("%d %d\n",s[n]-s[1],tot+2);
		printf("1 ");
		for (int i=1;i<=tot;i++) printf("%d ",d[i]); printf("%d\n",n);
	}
	return 0;
}