#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(1e5)+10;
int T,n,m,flag;
char s[maxn],t[maxn];
void solve(int l) {
	if (flag) return;
	for (int i=l,j=1;i<=n;i++) {
		if ((i-l+1)%2==j%2&&s[i]==t[j]) j++;
		if (j>m) { flag=(n-i)%2==0; break; }
	}
}
int main() {
	read(T); while (T--) {
		scanf("%s",s+1),scanf("%s",t+1);
		n=strlen(s+1),m=strlen(t+1);
		if (n<m) { puts("NO"); continue; }
		flag=0;
		for (int i=1;i<=n;i+=2) {
			if (s[i]==t[1]) { solve(i); break; }
		}
		for (int i=2;i<=n;i+=2) {
			if (s[i]==t[1]) { solve(i); break; }
		}
		if (flag) puts("YES"); else puts("NO");
	}
	return 0;
}