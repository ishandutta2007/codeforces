#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(1e5)+10;
int T,n,m,flag,x,ans;
int pos[maxn][30];
char s[maxn],t[maxn];
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		scanf("%s",s+1);
		scanf("%s",t+1);
		n=strlen(s+1);
		m=strlen(t+1);
		for (int j=1;j<=26;j++) pos[n+1][j]=0;
		for (int i=n;i>=1;i--) {
			for (int j=1;j<=26;j++) pos[i][j]=pos[i+1][j];
			pos[i][s[i]-'a'+1]=i;
		}
		flag=1;
		ans=1;
		x=0;
		for (int i=1;i<=m;i++) {
			x=pos[x+1][t[i]-'a'+1];
			if (!x) {
				ans++;
				x=pos[1][t[i]-'a'+1];
				if (!x) { flag=0; break; }
			}
		}
		if (!flag) ans=-1;
		printf("%d\n",ans);
	}
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