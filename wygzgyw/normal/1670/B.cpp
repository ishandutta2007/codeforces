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
int m; char t[10];
bool mk[300];
set<int> S;
int ans;
int pre[maxn],nxt[maxn];
void del(int x) {
	if (S.count(x)) S.erase(x);
	pre[nxt[x]]=pre[x];
	nxt[pre[x]]=nxt[x];
}
int main() {
	read(T);
	while (T--) {
		read(n);
		scanf("%s",s+1);
		read(m);
		for (int i='a';i<='z';i++) mk[i]=0;
		for (int i=1;i<=m;i++) {
			scanf("%s",t+1);
			mk[t[1]]=1;
		}
		S.clear();
		for (int i=1;i<=n;i++) if (mk[s[i]]) S.insert(i);
		for (int i=1;i<=n;i++) pre[i]=i-1,nxt[i]=i+1;
		int ans=0;
		while (S.size()) {
			vector<int> V;
			for (int x : S) if (pre[x]) V.push_back(pre[x]);
			if (!V.size()) break;
			ans++;
			for (int &x : V) del(x);
		}
		printf("%d\n",ans);
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