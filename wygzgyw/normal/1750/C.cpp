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
char s[maxn],t[maxn];
int F[maxn];
vector<pair<int,int> > ans;
void add(int l,int r) { ans.push_back(MP(l,r)); }
int main() {
	read(T);
	while (T--) {
		read(n); ans.clear();
		scanf("%s %s",s+1,t+1);
		int flag=1;
		for (int i=1;i<=n;i++) flag&=(s[i]!=t[i]);
		if (flag) {
			add(1,n);
			for (int i=1;i<=n;i++) s[i]^=1;
		}
		flag=1;
		for (int i=1;i<=n;i++) flag&=(s[i]==t[i]);
		if (!flag) { puts("NO"); continue; }
		for (int i=1;i<=n;i++) F[i]=0;
		for (int i=2;i<=n;i++) if (s[i]=='1') F[i]^=1,F[i-1]^=1;
		for (int i=1;i<=n;i++) if (F[i]) add(1,i);
		if (s[1]=='1') add(2,n),add(1,n);
		puts("YES");
		printf("%d\n",(int)ans.size());
		for (auto [x,y] : ans) printf("%d %d\n",x,y);
	}
	return 0;
}