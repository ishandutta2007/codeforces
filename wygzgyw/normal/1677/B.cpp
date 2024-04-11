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
const int maxn=(1e6)+10;
int T,n,m;
char s[maxn];
int pre[maxn],ans[maxn];
int sum[maxn];
int A(int x) { if (1<=x&&x<=n*m) return s[x]-'0'; return 0; }
int rub[maxn*5];
int *now,*S[maxn];
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n),read(m),scanf("%s",s+1);
		for (int i=0;i<=n*m+1;i++) sum[i]=pre[i]=ans[i]=0;
		now=rub;
		for (int i=0;i<m;i++) {
			S[i]=now,now+=n+2;
			for (int j=0;j<=n;j++) S[i][j]=0;
		}
		for (int i=1;i<=n*m;i++) {
			pre[i]=(i-m>0?pre[i-m]:0)+A(i);
			if (pre[i]) {
				sum[i]++;
				if (i+m<=n*m) sum[i+m]--;
			}
		}
		int now=0;
		for (int i=1;i<=n*m;i++) {
			now+=A(i)-A(i-m);
			if (now) {
				int bd=i+(n-1)*m;
				S[i%m][i/m]++;
				if (bd/m+1<=n) S[i%m][bd/m+1]--;
				//for (int j=i;j<=n*m&&j<=i+(n-1)*m;j+=m) ans[j]++;
			}
		}
		for (int i=0;i<m;i++) {
			for (int j=1;j<=n;j++) S[i][j]+=S[i][j-1];
		}
		for (int i=1;i<=n*m;i++) ans[i]+=S[i%m][i/m];
		for (int i=1;i<=n*m;i++) sum[i]+=sum[i-1],ans[i]+=sum[i];
		for (int i=1;i<=n*m;i++) printf("%d ",ans[i]); puts("");
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