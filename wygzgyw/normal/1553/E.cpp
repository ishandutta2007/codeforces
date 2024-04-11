#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(3e5)+10;
int T,n,m;
vector<int> ans;
int p[maxn],to[maxn],vis[maxn],cnt[maxn];
void check(int x) {
	for (int i=1;i<=n;i++) to[p[i]]=(i<=x?i+n-x:i-x);
	for (int i=1;i<=n;i++) vis[i]=0;
	int cnt=0;
	for (int i=1;i<=n;i++) if (!vis[i]) {
		cnt++;
		int x=i; while (1) { x=to[x]; vis[x]=1; if (x==i) break; }
	}
	if (n-cnt<=m) ans.push_back(x);
}
int main() {
	read(T); while (T--) {
		read(n),read(m); ans.clear();
		for (int i=0;i<n;i++) cnt[i]=0;
		for (int i=1;i<=n;i++) read(p[i]),cnt[(i-p[i]+n)%n]++;
		for (int i=0;i<n;i++) if (n-cnt[i]<=2*m) check(i);
		printf("%d ",(int)ans.size()); for (int &x : ans) printf("%d ",x); puts("");
	}
	return 0;
}