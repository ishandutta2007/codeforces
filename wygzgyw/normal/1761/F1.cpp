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
const int maxn=1010;
int n,p[maxn],d[maxn];
int ans,bk[maxn];
void update(int &x,int y) { x+=y; if (x>=mod) x-=mod; }
int dp[maxn][maxn];
bool chk(int x,int y) { return p[d[x]]==-1||p[d[x]]==y; }
int nxt(int x) { return (x+1)%n; }
int pre(int x) { return (x-1+n)%n; }
int t;
bool in(int x,int l,int r) {
	if (l<=r) return l<=x&&x<=r;
	return x>=l||r>=x;
}
bool query(int l,int r,int b,int c) {
	if (0<=c&&c<n) {
		if (b%2==t) return !in(bk[c],l,r);
		return in(bk[c],l,r);
	}
	return 1;
}
bool CHK(int l,int r,int b) {
	return query(l,r,b,b-1)&&query(l,r,b,b+1);
}
int main() {
	int T; read(T); while (T--) {
		ans=0;
		read(n);
		for (int i=0;i<n;i++) read(p[i]);
		for (t=0;t<=1;t++) {
			int tot=0;
			for (int i=0;i<n;i++) if (i%2==t) d[tot++]=i;
			for (int i=n-1;i>=0;i--) if (i%2!=t) d[tot++]=i;
			//for (int i=0;i<n;i++) printf("%d ",d[i]); puts("");
			for (int i=0;i<n;i++) bk[d[i]]=i;
			for (int i=0;i<n;i++) for (int j=0;j<n;j++) dp[i][j]=0;
			for (int len=1;len<n;len++) {
				for (int l=0;l<n;l++) {
					int r=(l+len-1)%n;
					if (l==r) { if (d[l]%2==t&&chk(l,n)) dp[l][r]=1; continue; }
					int b=n-len+1;
					if (chk(l,b)&&dp[nxt(l)][r]&&CHK(l,r,d[l])) update(dp[l][r],dp[nxt(l)][r]);
					if (chk(r,b)&&dp[l][pre(r)]&&CHK(l,r,d[r])) update(dp[l][r],dp[l][pre(r)]);
				}
			}
			for (int i=0;i<n;i++) if (chk(i,1)&&d[i]%2!=t) update(ans,dp[nxt(i)][pre(i)]);
		}
		printf("%d\n",ans);
	}
	return 0;
}