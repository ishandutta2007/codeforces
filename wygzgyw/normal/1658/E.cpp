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
const int maxn=2010;
int n,k,ans[maxn][maxn];
int val[maxn][maxn];
pair<int,int> pos[maxn*maxn];
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(k);
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) read(val[i][j]),pos[val[i][j]]=MP(i,j);
	}
	int mxA=-1e9,mxB=-1e9,mnA=1e9,mnB=1e9;
	int tmp;
	for (int I=n*n;I>=1;I--) {
		int i=pos[I].first,j=pos[I].second;
		int A=i+j,B=i-j;
		if (A-mnA>k||mxA-A>k||B-mnB>k||mxB-B>k) tmp=1;
		else {
			tmp=0;
			mxA=max(mxA,A);
			mnA=min(mnA,A);
			mxB=max(mxB,B);
			mnB=min(mnB,B);
		}
		ans[i][j]=tmp;
	}
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++)
			if (ans[i][j]) printf("G");
			else printf("M");
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