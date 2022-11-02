#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(3e5)+10;
int T,n,tot;
char ans[maxn],s[4][maxn];
int c[4][2],d[maxn],e[maxn],t1,t2;
void solve() {
	for (int i=1;i<=3;i++) for (int j=i+1;j<=3;j++) {
		if (min(c[i][0],c[j][0])>=n) {
			//printf("%d %d\n",i,j);
			t1=t2=0;
			for (int k=1;k<=n*2;k++) {
				if (s[i][k]=='0') d[++t1]=k;
				if (s[j][k]=='0') e[++t2]=k;
			} tot=0;
			for (int k=1;k<=min(t1,t2);k++) {
				for (int l=d[k-1]+1;l<d[k];l++) ans[++tot]=s[i][l];
				for (int l=e[k-1]+1;l<e[k];l++) ans[++tot]=s[j][l];
				ans[++tot]='0';
			}
			for (int l=d[min(t1,t2)]+1;l<=n*2;l++) ans[++tot]=s[i][l];
			for (int l=e[min(t1,t2)]+1;l<=n*2;l++) ans[++tot]=s[j][l];
			ans[tot+1]=0;
			assert(tot<=3*n);
			printf("%s\n",ans+1);
			return;
		}
		if (min(c[i][1],c[j][1])>=n) {
			t1=t2=0;
			for (int k=1;k<=n*2;k++) {
				if (s[i][k]=='1') d[++t1]=k;
				if (s[j][k]=='1') e[++t2]=k;
			} tot=0;
			for (int k=1;k<=min(t1,t2);k++) {
				for (int l=d[k-1]+1;l<d[k];l++) ans[++tot]=s[i][l];
				for (int l=e[k-1]+1;l<e[k];l++) ans[++tot]=s[j][l];
				ans[++tot]='1';
			}
			for (int l=d[min(t1,t2)]+1;l<=n*2;l++) ans[++tot]=s[i][l];
			for (int l=e[min(t1,t2)]+1;l<=n*2;l++) ans[++tot]=s[j][l];
			ans[tot+1]=0;
			assert(tot<=3*n);
			printf("%s\n",ans+1);
			return;
		}
	}
	//puts("WA");
}
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n);
		for (int i=1;i<=3;i++) {
			scanf("%s",s[i]+1);
			c[i][0]=c[i][1]=0;
			for (int j=1;j<=n*2;j++)
				c[i][s[i][j]-'0']++;
		}
		solve();
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