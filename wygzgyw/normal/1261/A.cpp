#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=2010;
int T,k,n;
char s[maxn],t[maxn];
struct node { int x,y; } d[maxn];
int tot;
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n); read(k); k--;
		scanf("%s",s+1);
		for (int i=1;i<=k;i++) t[i*2-1]='(',t[i*2]=')';
		for (int i=k*2+1,j=n;i<j;i++,j--) t[i]='(',t[j]=')';
		t[n+1]=0;
		//printf("%s\n",t+1);
		tot=0;
		for (int i=1;i<=n;i++) {
			if (s[i]==t[i]) continue;
			for (int j=i+1;j<=n;j++)
			if (t[i]==s[j]) {
				reverse(s+i,s+j+1);
				d[++tot]=(node){i,j};
				break;
			}
		}
		printf("%d\n",tot);
		for (int i=1;i<=tot;i++) printf("%d %d\n",d[i].x,d[i].y);
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