#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(1e5)+10;
int T,n,r,ans;
int d[maxn];
ll tmp;
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n); read(r);
		for (int i=1;i<=n;i++) read(d[i]);
		sort(d+1,d+n+1);
		n=unique(d+1,d+n+1)-d-1;
		int pos=n; tmp=ans=0;
		while (pos>=1) {
			if (d[pos]-tmp<=0) break;
			ans++; tmp+=r; pos--;
		}
		printf("%d\n",ans);
	}
	return 0;
}