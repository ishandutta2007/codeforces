#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(2e5)+10;
int T,n;
ll a[maxn],s[maxn];
ll mn[maxn][20],mx[maxn][20];
int rgt[maxn],lft[maxn];
int lg[maxn],st[maxn];
ll querymn(int l,int r) {
	int j=lg[r-l+1];
	return min(mn[l][j],mn[r-(1<<j)+1][j]);
}
ll querymx(int l,int r) {
	int j=lg[r-l+1];
	return max(mx[l][j],mx[r-(1<<j)+1][j]);
}
int main() {
	read(T);
	while (T--) {
		read(n); int k; read(k);
		for (int i=1;i<=n;i++) read(a[i]),s[i]=s[i-1]+a[i];
		for (int i=0;i<=n;i++) mn[i][0]=mx[i][0]=s[i];
		for (int i=2;i<=n+1;i++) lg[i]=lg[i>>1]+1;
		for (int i=1;i<=19;i++) for (int j=0;j+(1<<i)-1<=n;j++)
			mn[j][i]=min(mn[j][i-1],mn[j+(1<<i-1)][i-1]),
			mx[j][i]=max(mx[j][i-1],mx[j+(1<<i-1)][i-1]);
		
		int tot=0;
		for (int i=n;i>=1;i--) {
			while (tot&&s[st[tot]]<s[i]) tot--;
			rgt[i]=(!tot?-1:st[tot]),st[++tot]=i;
		}
		tot=0;
		for (int i=0;i<n;i++) {
			while (tot&&s[st[tot]]>s[i]) tot--;
			lft[i]=(!tot?-1:st[tot]),st[++tot]=i;
		}
		
		int l=k,r=k,flag=0;
		while (1) {
			if (l==1||r==n) { flag=1; break; }
			if (querymn(r+1,n)>=s[l-1]) { flag=1; break; }
			if (querymx(0,l-1)<=s[r]) { flag=1; break; }
			int fd=0,R=rgt[r];
			if (R!=-1&&querymn(r+1,R)>=s[l-1]) r=R,fd=1;
			int L=lft[l-1];
			if (L!=-1&&querymx(L,l-1)<=s[r]) l=L+1,fd=1;
			if (!fd) break;
		}
		if (flag) puts("YES"); else puts("NO");
	}
	return 0;
}