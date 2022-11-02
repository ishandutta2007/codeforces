#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=10010;
int n,m,cnt[maxn],ans[maxn],s,pos,tmp;
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(m);
	for (int i=1;i<=n;i++)
		s+=(i-1)/2;
	if (m>s) { printf("-1\n"); return 0; }
	if (m==s) {
		for (int i=1;i<=n;i++) printf("%d ",i); printf("\n"); return 0;
	}
	int x=0,pos;
	for (int i=1;i<=n;i++) {
		x=i; pos=i;
		if (m<=cnt[i]) break;
		m-=cnt[i];
		ans[i]=i;
		for (int j=1;j<i;j++) cnt[i+j]++;
	}
	while (cnt[x]!=m) x++;
	ans[pos]=x;
	s=ans[pos-1]+ans[pos]+1;
	tmp=s;
	for (int i=pos+1;i<=n;i++) {
		ans[i]=tmp;
		tmp+=2*s;
	}
	for (int i=1;i<=n;i++) printf("%d ",ans[i]);
	printf("\n");
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