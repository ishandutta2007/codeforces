#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(1e6)+10;
int T,n,pos,a[maxn];
char s[maxn];

int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		scanf("%s",s+1);
		n=strlen(s+1);
		for (int i=0;i<=n*2;i++) a[i]=0;
		pos=n;
		for (int i=1;i<=n;i++) {
			if (s[i]=='0') pos--,a[pos]++;
			else a[pos]++,pos++;
		}
		int l=n*2,r=0;
		for (int i=0;i<=n*2;i++) if (a[i]) l=min(l,i),r=max(r,i);
		pos=n;
		for (int i=1;i<=n;i++) {
			if (a[pos-1]&&!(a[pos-1]==1&&pos<=r)) {
				a[pos-1]--,pos--;
				putchar('0');
			} else {
				a[pos]--,pos++;
				putchar('1');
			}
			while (l<r&&!a[l]) l++;
			while (l<r&&!a[r]) r--;
		}
		puts("");
	}
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Interger overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/