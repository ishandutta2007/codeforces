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
typedef long long ll;
const int maxn=(2e5)+10;
int T,n,N;
char s[maxn];
ll ans,a,b,c;
int d[maxn],tot,cnt,c2;
int main() {
	read(T);
	while (T--) {
		read(n); read(a),read(b),read(c);
		scanf("%s",s+1);
		if (n==1) { puts("0"); continue; }
		int F0=1,F1=1;
		for (int i=1;i<=n;i++) F0&=(s[i]=='0'),F1&=(s[i]=='1');
		if (F0) { printf("%lld\n",a); continue; }
		if (F1) { printf("%lld\n",b); continue; }
		int c0=0,c1=0;
		for (int i=1;i<n;i++) {
			if (s[i]==s[i+1]) {
				if (s[i]=='0') c0++; else c1++;
			}
		}
		tot=cnt=c2=0;
		for (int i=1,j;i<=n;i=j+1) if (s[i]=='0') {
			j=i; while (j<n&&s[j+1]=='0') j++;
			if (1<i&&j<n) d[++tot]=j-i; else cnt++;
		} else j=i;
		int mn=min(c0,c1);
		c0-=mn,c1-=mn; ans=(a+b)*mn;
		if (c0) ans+=a,c0--; if (c1) ans+=b,c1--;
		if (b-c<=0) { printf("%lld\n",ans); continue; }
		sort(d+1,d+tot+1);
		for (int i=1;i<=tot;i++) if (mn>=d[i]) mn-=d[i],c2++;
		c2+=min(cnt,c1);
		ans+=(b-c)*c2;
		printf("%lld\n",ans);
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