#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
int n,m,pos[110],tmp,ans[110],mx;
char s[110][60];
bool check(int x,int y) {
	for (int i=1;i<=m;i++)
		if (s[x][i]!=s[y][m-i+1]) return 0;
	return 1;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(m);
	for (int i=1;i<=n;i++) scanf("%s",s[i]+1);
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) {
			if (check(i,j)) {
				if (i==j) pos[i]=-1;
				else pos[i]=j;
				break;
			}
		}
	}
	for (int i=0;i<=n;i++) {
		if (i&&pos[i]!=-1) continue;
		if (i) tmp=1; else tmp=0;
		for (int j=1;j<=n;j++) {
			if (i==j) continue;
			if (pos[j]>0) tmp++;
		}
		if (tmp>mx) {
			mx=tmp;
			int tot=0;
			for (int j=1;j<=n;j++)
				if (pos[j]&&j<pos[j]) ans[++tot]=j;
			if (i) ans[++tot]=i;
			for (int j=n;j>=1;j--)
				if (pos[j]&&j<pos[j]) ans[++tot]=pos[j];
		}
	}
	printf("%d\n",mx*m);
	for (int i=1;i<=mx;i++) printf("%s",s[ans[i]]+1);
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