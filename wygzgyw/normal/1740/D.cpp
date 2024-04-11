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
int T,n,m,k,p[maxn],pos[maxn];

int main() {
	read(T);
	while (T--) {
		read(n),read(m),read(k);
		int now=0;
		for (int i=1;i<=k;i++) read(p[i]),pos[p[i]]=i;
		int mx=0,flag=1;
		for (int i=k;i>=1;i--) {
			int x=pos[i];
			if (x<mx) now--;
			else {
				now+=x-mx-1;
				if (now+1>=n*m-2) { flag=0; break; }
			}
			mx=max(mx,x);
		}	
		if (!flag) puts("TIDAK"); else puts("YA");
	}
	return 0;
}