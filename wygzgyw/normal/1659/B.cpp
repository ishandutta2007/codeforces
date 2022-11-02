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
int T,n,k;
int flag,ans[maxn];
char s[maxn],t[maxn],mx[maxn];
int now[maxn];
void check(vector<int> V) {
//	for (int &x : V) printf("%d ",x); puts("");
	while ((int)V.size()>k) V.pop_back();
	if ((int)V.size()%2!=k%2) return;
	for (int i=1;i<=n;i++) t[i]=s[i];
	for (int &x : V) t[x]^=1;
	//for (int i=1;i<=n;i++) printf("%c",t[i]); puts("");
	int F=0;
	for (int i=1;i<=n;i++) if (t[i]!=mx[i]) { F=(t[i]>mx[i]); break; }
	if (F||!flag) {
		for (int i=1;i<=n;i++) mx[i]=t[i];
		for (int i=1;i<=n;i++) ans[i]=0;
		for (int &x : V) ans[x]=1;
		ans[1]+=(k-(int)V.size());
	}
	flag=1;
}
vector<int> V;
int main() {
	read(T);
	while (T--) {
		read(n),read(k);
		scanf("%s",s+1);
		for (int i=1;i<=n;i++) if (k&1) s[i]^=1;
		vector<int> V;
		for (int i=1;i<=n;i++) {
			if (s[i]=='0') V.push_back(i);
		}
		flag=0;
		check(V);
		int fd=0;
		for (int i=n;i>=1;i--) if (s[i]=='1') { fd=i; break; }
		if (fd) V.push_back(fd),check(V),V.pop_back();
		if ((int)V.size()) V.pop_back(),check(V);
		mx[n+1]=0;
		printf("%s\n",mx+1);
		for (int i=1;i<=n;i++) printf("%d ",ans[i]); puts("");
	}
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Integer overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/