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
int n,m;
char s[1000];
int l[1000],S[1000];
int id[1000];
bool cmp(int x,int y) { return l[x]<l[y]; }
int main() {
	scanf("%d %d",&n,&m);
	for (int i=1;i<=m;i++) {
		for (int j=1;j<=m;j++) s[j]='0';
		s[i]='1';
		printf("? %s\n",s+1); fflush(stdout);
		scanf("%d",&l[i]); id[i]=i;
	}
	sort(id+1,id+m+1,cmp);
	int ans=0;
	for (int i=1;i<=m;i++) {
		for (int j=1;j<=m;j++) s[j]='0';
		for (int j=1;j<=i;j++) s[id[j]]='1';
		printf("? %s\n",s+1); fflush(stdout);
		scanf("%d",&S[i]);
		if (S[i]==S[i-1]+l[id[i]]) ans+=l[id[i]];
	}
	printf("! %d\n",ans); fflush(stdout);
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