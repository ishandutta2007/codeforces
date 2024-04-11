#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(1e7)+(5e6)+5;
int n,a[300010],cnt[maxn];
int tmp,ans,g;
bool vis[maxn];
int gcd(int x,int y) {
	if (!x||!y) return x+y;
	return gcd(y,x%y);
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;++i) {
		read(a[i]);
		g=gcd(g,a[i]);
	}
	for (int i=1;i<=n;++i)
		cnt[a[i]/g]++;
	for (register int i=2;i<maxn;++i)
		if (!vis[i]) {
			tmp=0;
			for (register int j=i;j<maxn;j+=i)
				vis[j]=1,tmp+=cnt[j];
			ans=max(ans,tmp);
		}
	ans=n-ans;
	if (ans==n) ans=-1;
	printf("%d\n",ans);
	return 0;
}