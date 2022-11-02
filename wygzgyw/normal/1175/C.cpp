#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(2e5)+10;
int T,n,k,a[maxn];
int ans,x,tmp;
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n); read(k); k++;
		for (int i=1;i<=n;i++) read(a[i]);
		ans=(1e9);
		for (int i=1;i+k-1<=n;i++) {
			tmp=a[i+k-1]-a[i];
			if (tmp<ans) { ans=tmp; x=(a[i+k-1]+a[i])/2; }
		}
		printf("%d\n",x);
	}
	return 0;
}