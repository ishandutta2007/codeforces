#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}

int T,ans,d[5];

int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		for (int i=1;i<=4;i++) read(d[i]);
		sort(d+1,d+5);
		ans=0;
		do {
			ans=max(ans,min(d[1],d[2])*min(d[3],d[4]));
		} while (next_permutation(d+1,d+5));
		printf("%d\n",ans);
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