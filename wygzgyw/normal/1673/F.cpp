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
int n;
int a[40][40],sum;
vector<int> V;
pair<int,int> rem[1200];
int main() {
	n=32;
	V.push_back(0),V.push_back(1);
	while ((int)V.size()<32) {
		int x=(int)V.size();
		for (int i=x-1;i>=0;i--) V.push_back(V[i]+x);
	}
	int tot=0;
	for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) {
		int x=V[i-1],y=V[j-1];
		for (int k=0;k<10;k++) if (k&1) a[i][j]|=(x&1)<<k,x>>=1; else a[i][j]|=(y&1)<<k,y>>=1;
		rem[a[i][j]]=MP(i,j);
	}
	read(n);
	int T; read(T);
	for (int i=1;i<=n;i++) {
		for (int j=1;j<n;j++) {
			int x=(a[i][j]^a[i][j+1]);
			sum+=x;
			printf("%d ",x);
		}
		puts("");
	}
	for (int i=1;i<n;i++) {
		for (int j=1;j<=n;j++) {
			int x=(a[i][j]^a[i+1][j]);
			sum+=x;
			printf("%d ",x);
		}
		puts("");
	} fflush(stdout);
	int lst=0,x;
	while (T--) {
		read(x);
		x^=lst;
		printf("%d %d\n",rem[x].first,rem[x].second);
		fflush(stdout);
		lst=x;
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