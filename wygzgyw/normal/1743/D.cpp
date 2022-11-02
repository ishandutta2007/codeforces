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
const int maxn=(1e6)+10;
int n;
char ans[maxn],s[maxn];
int d[maxn],tot,mx,pos,tmp;
int main() {
	read(n);
	scanf("%s",s+1);
	reverse(s+1,s+n+1);
	while (s[n]=='0'&&n) n--;
	if (!n) { puts("0"); return 0; }
	reverse(s+1,s+n+1);
	for (int i=1;i<=n;i++) if (s[i]=='0') d[++tot]=i;
	if (tot) {
		for (int i=1;i<=n;i++) ans[i]=s[i];
		for (int i=1;i<=n;i++) if (s[i]=='1') {
			int x=d[1];
			int j=n-x+i;
			if (j>n) continue;
			for (int v1=i,v2=x;v1<=j;v1++,v2++) {
				int t=(s[v1]-'0')|(s[v2]-'0');
				if (ans[v2]!=t+'0') {
					if (ans[v2]<t+'0') {
						for (int k1=i,k2=x;k1<=j;k1++,k2++) {
							ans[k2]=((s[k1]-'0')|(s[k2]-'0'))+'0';
						}
					}
					break;
				}
			}
		}
	}
	for (int i=1;i<=n;i++) printf("%c",ans[i]); puts("");
	return 0;
}