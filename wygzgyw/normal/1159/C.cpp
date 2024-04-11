#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(1e5)+10;
typedef long long ll;
int n,m;
ll a[maxn],b[maxn];
ll mn=(1e9),mx,ans,pre;
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(m);
	for (int i=1;i<=n;i++) {
		read(a[i]),ans+=a[i]*m;
		if (a[i]>=mx) pre=mx,mx=a[i];
		else pre=max(pre,a[i]);
	}
	for (int i=1;i<=m;i++)
		read(b[i]),mn=min(mn,b[i]),ans+=b[i]-mx;
	if (mn!=mx) ans+=mx-pre;
	if (mx>mn) { printf("-1\n"); return 0; }
	printf("%lld\n",ans);
	return 0;
}