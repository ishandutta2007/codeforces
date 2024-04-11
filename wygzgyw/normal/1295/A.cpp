#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
int T,n;
int cnt[10];
int main() {
	//freopen("1.txt","r",stdin);
	cnt[9]=6;
	cnt[8]=7;
	cnt[7]=3;
	cnt[6]=6;
	cnt[5]=5;
	cnt[4]=4;
	cnt[3]=5;
	cnt[2]=5;
	cnt[1]=2;
	cnt[0]=6;
	read(T);
	while (T--) {
		read(n);
		if (n&1) printf("7"),n-=3;
		for (int i=1;i<=n/2;i++) printf("1");
		printf("\n");
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