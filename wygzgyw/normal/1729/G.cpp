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
typedef long long ll;
const int mod=(1e9)+7;
const int maxn=510;
const int INF=1e9;
int T,d[maxn],tot,C[maxn][maxn];
char s[maxn],t[maxn];
int n,m;
int L[maxn],R[maxn];
struct node {
	int a,b;
	friend node operator + (node A,node B) {
		node res; res.a=A.a+B.a+1;
		res.b=(ll)A.b*B.b%mod;
		return res;
	}
} dp[maxn][maxn];
void update(int &x,int y) { x+=y; if (x>=mod) x-=mod; }
void chkmin(node &A,node B) {
	if (A.a>B.a) A=B;
	else if (A.a==B.a) update(A.b,B.b);
}
int main() {
	//freopen("1.txt","r",stdin);
	for (int i=0;i<maxn;i++) {
		C[i][0]=C[i][i]=1;
		for (int j=1;j<i;j++) C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
	read(T);
	while (T--) {
		scanf("%s",s+1),scanf("%s",t+1);
		n=strlen(s+1),m=strlen(t+1);
		tot=0;
		for (int i=1;i<=n-m+1;i++) {
			int flag=1; for (int j=1;j<=m&&flag;j++) flag&=(t[j]==s[i+j-1]);
			if (flag) d[++tot]=i;
		}
		for (int i=1;i<=tot;i++) {
			for (int j=i;j>=1;j--) if (d[j]+m-1>=d[i]) L[i]=j; else break;
			for (int j=i;j<=tot;j++) if (d[j]<=d[i]+m-1) R[i]=j; else break;
		}
		//for (int i=1;i<=tot;i++) printf("%d %d %d\n",d[i],L[i],R[i]);
		for (int len=1;len<=tot;len++) for (int l=1;l+len-1<=tot;l++) {
			int r=l+len-1;
			dp[l][r].a=INF;
			for (int i=l;i<=r;i++) if (L[i]<=l) {
				node A,B;
				if (L[i]-1>=l) A=dp[l][L[i]-1]; else A=(node){0,1};
				if (R[i]+1<=r) B=dp[R[i]+1][r]; else B=(node){0,1};
				A=A+B;
				chkmin(dp[l][r],A);
			}
		}
		if (!tot) printf("0 1\n");
		else printf("%d %d\n",dp[1][tot].a,dp[1][tot].b);
	}
	return 0;
}