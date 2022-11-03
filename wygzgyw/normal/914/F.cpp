#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(1e5)+10;
int n,q;
char s[maxn],t[maxn],c[2],ch;
bitset<maxn> d[30],msk,ans;
int main() {
	//freopen("1.txt","r",stdin);
	scanf("%s",s+1);
	n=strlen(s+1);
	for (int i=1;i<=n;i++) d[s[i]-'a'+1][i]=1;
	for (int i=0;i<n;i++) msk[i]=1;
	read(q);
	int op,l,r,x;
	while (q--) {
		read(op);
		if (op==1) {
			read(x);
			scanf("%s",c+1);
			ch=c[1];
			d[s[x]-'a'+1][x]=0;
			s[x]=ch;
			d[s[x]-'a'+1][x]=1;
		} else {
			read(l); read(r);
			scanf("%s",t+1);
			x=strlen(t+1);
			if (r-l+1<x) { printf("0\n"); continue; }
			ans=msk;
			for (int i=1;i<=x;i++)
				ans&=d[t[i]-'a'+1]>>i;
			printf("%d\n",(ans>>(l-1)).count()-(ans>>(r-x+1)).count());
		}
	}
	return 0;
}
/*
  REMEMBER:
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Array size? Integer overflow? Time complexity? Memory usage? Precision error?
*/