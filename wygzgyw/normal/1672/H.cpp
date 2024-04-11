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
int n,q;
char s[maxn];
struct node { int l,r,tp; } d[maxn];
int tot,bel[maxn],X[maxn],Y[maxn];
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(q);
	scanf("%s",s+1);
	for (int i=1;i<=n;i++) {
		if (i>1&&s[i]!=s[i-1]) d[tot].r++;
		else tot++,d[tot].l=d[tot].r=i;
	}
	for (int i=1;i<=tot;i++) for (int j=d[i].l;j<=d[i].r;j++) bel[j]=i;
	for (int i=1;i<=tot;i++) {
		int len=((d[i].r-d[i].l+1)&1^1);
		d[i].tp=(len<<1)+('1'-s[d[i].l]);
		X[i]=X[i-1],Y[i]=Y[i-1];
		if (d[i].tp==0) X[i]++; else if (d[i].tp==1) X[i]--;
		else if (d[i].tp==2) Y[i]++; else Y[i]--;
		
		//printf("%d %d %d\n",d[i].l,d[i].r,d[i].tp);
		
	}
	while (q--) {
		int x,y; read(x),read(y);
		x=bel[x],y=bel[y];
		int a=y-x+1,b;
		int t1=X[y]-X[x-1],t2=Y[y]-Y[x-1];
		b=abs(t1);
		x=d[x].l,y=d[y].r;
		if (abs(t2)==1) b++;
		else if (s[x]==s[y]) {
			if (t1>0&&s[x]=='0') b+=2;
			else if (t1<0&&s[x]=='1') b+=2;
			else if (d[bel[x]].tp>1&&bel[y]==bel[x]+1) b+=2;
			else if (t1==0&&t2==0) b+=2;
		}
		//printf("%d %d %d %d, %d %d\n",bel[x],bel[y],a,b,t1,t2);
		printf("%d\n",(a-b)/2+b);
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