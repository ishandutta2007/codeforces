#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=10010;
int T,n,cnt[maxn],tot,d[maxn];
int solve() {
	tot=0;
	for (int i=1;i<maxn;i++)
		if (cnt[i]%2==1) return 0;
		else {
			for (int j=1;j<=cnt[i]/2;j++)
				d[++tot]=i;
		}
	sort(d+1,d+tot+1); int s=-1,tmp;
	for (int i=1;i<=n;i++) {
		tmp=d[i]*d[tot-i+1];
		if (s==-1) s=tmp;
		if (s!=tmp) return 0;
	}
	return 1;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		memset(cnt,0,sizeof(cnt));
		read(n); int x;
		for (int i=1;i<=n*4;i++) read(x),cnt[x]++;
		if (solve()) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}