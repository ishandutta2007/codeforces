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
int n,m,f1[maxn],f2[maxn],len,ok[maxn];
char s[maxn],t[maxn];
int ch[maxn][26],p[maxn],tot;
string rem[maxn];
int main() {
	read(n);
	scanf("%s",s+1);
	tot=1;
	read(m);
	for (int i=1;i<=m;i++) {
		scanf("%s",t+1); len=strlen(t+1);
		int pos=1;
		for (int j=1;j<=len;j++) {
			rem[i]+=t[j];
			int tmp=('a'<=t[j]&&t[j]<='z'?t[j]-'a':t[j]-'A');
			if (!ch[pos][tmp]) ch[pos][tmp]=++tot;
			pos=ch[pos][tmp];
		}
		p[pos]=i;
	}
	ok[0]=1;
	for (int i=1;i<=n;i++) {
		int pos=1;
		for (int j=i;j>=1&&j>=i-1000+1;j--) {
			int tmp=s[j]-'a';
			if (!ch[pos][tmp]) break;
			pos=ch[pos][tmp];
			if (p[pos]&&ok[j-1]) { ok[i]=1; f1[i]=j-1,f2[i]=p[pos]; break; }
		}
	}
	int x=n; vector<int> V;
	while (x) {
		V.push_back(f2[x]);
		x=f1[x];
	}
	reverse(V.begin(),V.end());
	for (int &x : V) cout<<rem[x]<<" ";
	cout<<endl;
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