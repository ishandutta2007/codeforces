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
const int maxn=(3e5)+10;
int T,n;
char s[maxn];
bool vis[30];
int to[30];
bool chk(int x,int y) {
	while (x) {
		if (x==y) return 0;
		x=to[x];
	}
	return 1;
}
int main() {
	read(T);
	while (T--) {
		read(n);
		scanf("%s",s+1);
		memset(to,0,sizeof(to));
		memset(vis,0,sizeof(vis));
		int cnt=26;
		for (int i=1;i<=n;i++) {
			int t=s[i]-'a'+1;
			if (!to[t]) {
				for (int j=1;j<=26;j++) if (j!=t&&!vis[j]&&(cnt==1||chk(j,t))) { to[t]=j; vis[j]=1; cnt--; break; }
			}
			printf("%c",to[t]+'a'-1);
		} puts("");
	}
	return 0;
}