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
const int maxn=(4e5)+10;
int T,n;
char s[maxn];
int mat[maxn];
int ans,st[maxn],tot;
void dfs(int l,int r) {
	if (l>r) return;
	ans++;
	int x=l;
	while (x<r) {
		dfs(x+1,mat[x]-1);
		x=mat[x]+1;
	}
}

int main() {
	read(T);
	while (T--) {
		read(n);
		scanf("%s",s+1);
		tot=0;
		for (int i=1;i<=n*2;i++) {
			if (s[i]=='(') st[++tot]=i; else mat[st[tot]]=i,tot--;
		}
		ans=0;
		dfs(1,n*2);
		printf("%d\n",ans);
	}
	return 0;
}