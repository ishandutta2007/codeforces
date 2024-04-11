#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(3e5)+10;
int n,q,ans,cnt;
int op,x,a[maxn],b[maxn],c[maxn];
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(q);
	int now=0;
	while (q--) {
		read(op),read(x);
		if (op==1) a[++cnt]=x,b[x]++,c[x]++,ans++;
		else if (op==2) ans-=b[x],b[x]=0;
		else {
			while (now<x) {
				now++;
				if (c[a[now]]) c[a[now]]--;
				if (b[a[now]]>c[a[now]]) ans--,b[a[now]]--;
			}
		}
		printf("%d\n",ans);
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