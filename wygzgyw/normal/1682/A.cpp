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
typedef unsigned long long ull;
const ull M=233333;
const int maxn=(2e5)+10;
int T,n;
ull s1[maxn],s2[maxn];
ull mi[maxn];
ull q1(int l,int r) {
	return (s1[r]-s1[l-1])*mi[n-r];
}
ull q2(int l,int r) {
	return (s2[l]-s2[r+1])*mi[l-1];
}
char s[maxn];
int main() {
	read(T);
	mi[0]=1; for (int i=1;i<maxn;i++) mi[i]=mi[i-1]*M;
	while (T--) {
		read(n);
		scanf("%s",s+1);
		s1[0]=s2[n+1]=0;
		for (int i=1;i<=n;i++) s1[i]=s1[i-1]+mi[i]*s[i];
		for (int i=n;i>=1;i--) s2[i]=s2[i+1]+mi[n-i+1]*s[i];
		int ans=0;
		for (int i=1;i<=(n+1)/2;i++) {
			if (n%2==1&&i==n/2+1) { ans++; continue; }
			int l=i+1,r=n-(i-1);
			int len=(r-l+1);
			int mid=(l+r)>>1;
			if (len%2==1) {
				if (q1(l,mid)==q2(mid,r)) ans+=2;
			} else {
				if (q1(l,mid)==q2(mid+1,r)) ans+=2;
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