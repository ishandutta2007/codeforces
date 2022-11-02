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
const int maxn=1010;
int T,n,m,dp[maxn],from[maxn];
char s[maxn],t[maxn][maxn];
struct node { int l,r,i; } A[maxn],p3[1010],p2[110];
void update(node &A,int i,int l,int r) { A=(node){l,r,i}; }

int main() {
	read(T); while (T--) {
		read(n),read(m);
		for (int i=1;i<=n;i++) scanf("%s",t[i]+1);
		scanf("%s",s+1);
		for (int i=0;i<100;i++) p2[i]=(node){0,0,0};
		for (int i=0;i<1000;i++) p3[i]=(node){0,0,0};
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=m;j++) {
				if (j>=2) update(p2[(t[i][j-1]-'0')*10+t[i][j]-'0'],i,j-1,j);
				if (j>=3) update(p3[(t[i][j-2]-'0')*100+(t[i][j-1]-'0')*10+t[i][j]-'0'],i,j-2,j);
			}
		}
		dp[0]=1; for (int i=1;i<=m;i++) dp[i]=0;
		for (int i=1;i<=m;i++) {
			for (int j=max(0,i-3);j<=i-2;j++) {
				//j+1...i
				int tmp=0;
				for (int k=j+1;k<=i;k++) tmp=tmp*10+s[k]-'0';
				node G;
				if (j==i-3) {
					G=p3[tmp];
				} else G=p2[tmp];
				if (G.l&&dp[j]) dp[i]=1,from[i]=j,A[i]=G;
				//printf("%d %d %d %d %d\n",dp[j],j,i,tmp,G.l);
			}
			//if (dp[i]) printf("%d\n",i);
		}
		vector<node> ans;
		if (!dp[m]) { puts("-1"); continue; }
		int t=m;
		while (t) {
			ans.push_back(A[t]); t=from[t];
		} reverse(ans.begin(),ans.end());
		printf("%d\n",(int)ans.size());
		for (node &A : ans) printf("%d %d %d\n",A.l,A.r,A.i);
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