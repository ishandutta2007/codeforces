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
const int maxn=(1e5)+10;
int T,n;
char s[maxn];
int ans;
int k,a,b,cnt;
int main() {
	read(T);
	while (T--) {
		read(n); read(k);
		scanf("%s",s+1);
		cnt=a=b=0;
		for (int i=1;i<=n;i++) {
			if (s[i]=='1') {
				cnt++;
				if (!a) a=i;
				b=i;
			}
		}
		if (!cnt) ans=0;
		else {
			if (n==2) {
				if (cnt==2) ans=11;
				else if (s[1]=='1') {
					if (k) ans=1; else ans=10;
				} else ans=1;
			} else {
				a=a-1,b=n-b;
				if (cnt==1) {
					if (b<=k) ans=1;
					else if (a<=k) ans=10;
					else ans=11;
				} else {
					ans=11*cnt;
					if (a+b<=k) ans-=11;
					else if (b<=k) ans-=10;
					else if (a<=k) ans--;
				}
			}
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