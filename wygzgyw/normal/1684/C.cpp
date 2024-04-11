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
const int maxn=(4e5)+10;
int T,n,m,rub[maxn];
int *now;
int *d[maxn];
int e[maxn],flag;
int main() {
//	freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n),read(m);
		now=rub; flag=1;
		for (int i=1;i<=n;i++) d[i]=now,now+=m+1;
		int X=-1,Y=-1;
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=m;j++) read(d[i][j]),e[j]=d[i][j];
			sort(e+1,e+m+1);
			vector<int> V;
			for (int j=1;j<=m;j++) if (d[i][j]!=e[j]) {
				flag=0;
				V.push_back(j);
			}
			if ((int)V.size()>2) flag=-1;
			if ((int)V.size()==2) {
				int x=V[0],y=V[1];
			//	printf("> %d %d\n",x,y);
				if (X==-1) X=x,Y=y;
				else if (X!=x||Y!=y) flag=-1;
			}
		}
		if (flag==-1) { puts("-1"); continue; }
		if (flag==1) { puts("1 1"); continue; }
		flag=1;
		for (int i=1;i<=n;i++) {
			swap(d[i][X],d[i][Y]);
			for (int j=1;j<m;j++) flag&=(d[i][j]<=d[i][j+1]);
		}
		if (flag) printf("%d %d\n",X,Y);
		else puts("-1");
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