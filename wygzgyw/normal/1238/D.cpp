#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(3e5)+10;
typedef long long ll;
ll ans;
int n,tot,d[maxn];
char s[maxn];
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	scanf("%s",s+1);
	for (int i=1;i<=n;i++) {
		if (s[i]!=s[i-1]) tot++;
		d[tot]++;
	}
	for (int i=1;i<=tot;i++) {
		if (i<tot) ans+=d[i+1];
		if (i>1) ans+=d[i-1];
	}
	ans+=n; ans-=tot-1;
	printf("%lld\n",(ll)n*(n+1)/2-ans);
	return 0;
}