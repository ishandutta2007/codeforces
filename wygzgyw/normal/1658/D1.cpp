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
const int maxn=(1<<17)+10;
int T,l,r,len;
int a[maxn],mk[maxn];
int tot,ch[maxn*18][2];
int cnt[maxn*18];
int query(int x,int r) {
	int res=0;
	if (mk[x^r]) res++;
	int pos=1;
	for (int i=16;i>=0;i--) {
		int t=(x>>i&1);
		if (r>>i&1) {
			res+=cnt[ch[pos][t]];
			pos=ch[pos][t^1];
		} else pos=ch[pos][t];
	}
	//printf("%d %d %d\n",x,r,res);
	return res;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(l),read(r);
		len=r-l+1;
		for (int i=1;i<=len;i++) read(a[i]),mk[a[i]]=1;
		tot=1;
		for (int i=1;i<=len;i++) {
			int pos=1;
			for (int j=16;j>=0;j--) {
				int t=(a[i]>>j&1);
				if (!ch[pos][t]) ch[pos][t]=++tot;
				pos=ch[pos][t];
				cnt[pos]++;
			}
		}
		for (int i=1;i<=len;i++) {
			int x=(a[i]^l);
			if (query(x,r)-(l==0?0:query(x,l-1))==r-l+1) { printf("%d\n",x); break; }
		}
		for (int i=1;i<=len;i++) mk[a[i]]=0;
		for (int i=1;i<=tot;i++) cnt[i]=0,ch[i][0]=ch[i][1]=0;
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