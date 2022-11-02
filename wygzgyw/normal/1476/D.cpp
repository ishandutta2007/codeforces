#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(3e5)+10;
int T,n,l[maxn],r[maxn];
char s[maxn];
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n);
		scanf("%s",s+1);
		for (int i=0;i<=n;i++) l[i]=r[i]=0;
		if (s[1]=='L') l[1]=1;
		for (int i=2;i<=n;i++) {
			if (s[i-1]=='R'&&s[i]=='L') l[i]=l[i-2]+2;
			else if (s[i]=='L') l[i]=1;
		}
		if (s[n]=='R') r[n-1]=1;
		for (int i=n-2;i>=0;i--) {
			if (s[i+1]=='R'&&s[i+2]=='L') r[i]=r[i+2]+2;
			else if (s[i+1]=='R') r[i]=1;
		}
		for (int i=0;i<=n;i++) printf("%d ",l[i]+r[i]+1);
		puts("");
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