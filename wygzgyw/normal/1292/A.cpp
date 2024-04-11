#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(1e5)+10;
int n,q,ans;
bool d[2][maxn];
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(q);
	int x,y,delta;
	while (q--) {
		read(x); read(y);
		x--;
		if (d[x][y]) delta=-1;
		else delta=1;
		d[x][y]^=1;
		for (int i=-1;i<=1;i++)
			if (d[x^1][y+i]) ans+=delta;
		if (!ans) printf("Yes\n");
		else printf("No\n");
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