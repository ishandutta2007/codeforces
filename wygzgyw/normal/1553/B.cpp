#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=1010;
int T,n,m;
char s[maxn],t[maxn];
void solve() {
	for (int i=1;i<=n;i++) {
		int flag=1;
		for (int j=i,k=1;j<=n&&k<=m;j++,k++) {
			flag&=(s[j]==t[k]);
			if (flag) {
				int f=1;
				for (int l=j-1,v=k+1;v<=m;v++,l--) {
					if (l<1) { f=0; break; }
					if (s[l]!=t[v]) { f=0; break; }
				}
				if (f) { puts("YES"); return; }
			} else break;
		}
	}
	puts("NO");
}
int main() {
	read(T); while (T--) {
		scanf("%s",s+1),scanf("%s",t+1);
		n=strlen(s+1),m=strlen(t+1);
		solve();
	}
	return 0;
}