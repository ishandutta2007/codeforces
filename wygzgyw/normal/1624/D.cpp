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
int T,n,cnt[30],K;
char s[maxn];
int A,B;
bool check(int mid) {
	int a=A,b=B;
	if (mid%2==0) {
		a-=(mid/2)*K;
		return a>=0;
	}
	for (int I=0;I<=A;I++) {
		a=A-I,b=B+2*I; b=min(b,K);
		a-=b*(mid/2);
		a-=(K-b)*(mid/2+1);
		if (a>=0&&b>=0) return 1;
	}
	return 0;
}
int main() {
	read(T);
	while (T--) {
		read(n); read(K);
		scanf("%s",s+1); memset(cnt,0,sizeof(cnt));
		for (int i=1;i<=n;i++) cnt[s[i]-'a']++; A=B=0;
		for (int i=0;i<26;i++) {
			if (cnt[i]&1) B++,cnt[i]--; A+=cnt[i]/2;
		}
		int l=1,r=n/K,mid,res=-1;
		while (l<=r) {
			mid=(l+r)/2; if (check(mid)) res=mid,l=mid+1; else r=mid-1;
		}
		printf("%d\n",res);
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