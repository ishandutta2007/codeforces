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
vector<int> V;
char s[maxn];
void add(int x,int y) {
	printf("%d %d\n",x+1,y+1);
}
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n);
		scanf("%s",s);
		int cnt=0;
		for (int i=0;i<n;i++) if (s[i]=='1') cnt++;
		if ((cnt&1)||cnt==0) { puts("NO"); continue; } 
		int fd=0;
		for (int i=0;i<n;i++) if (s[i]=='1') fd=i;
		fd=(fd-1+n)%n;
		V.clear();
		for (int i=1;i<n;i++) {
			int x=(i+fd)%n;
			if (s[x]=='1') V.push_back(i);
		}
		puts("YES");
		for (int i=0;i<V.size();i++) {
			int j=(i==(int)V.size()-1?n-1:V[i+1]-1);
			for (int k=V[i];k<j;k++) add((fd+k)%n,(fd+k+1)%n);
			//printf("fd=%d\n",fd);
			add(fd,(fd+j)%n);
		}
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