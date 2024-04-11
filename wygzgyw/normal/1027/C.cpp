#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(1e6)+10;
int T,n,a[maxn],b[maxn],tot,ans;
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n);
		for (int i=1;i<=n;i++) read(a[i]);
		sort(a+1,a+(n+1));
		tot=0;
		for (int i=2;i<=n;i++)
			if (a[i]==a[i-1]) {
				b[++tot]=a[i];
				a[i]=0;
			}
		ans=2;
		for (int i=3;i<=tot;i++)
			if ((ll)b[ans]*b[i-1]>(ll)b[ans-1]*b[i]) ans=i;
		printf("%d %d %d %d\n",b[ans],b[ans],b[ans-1],b[ans-1]);
	}
	return 0;
}