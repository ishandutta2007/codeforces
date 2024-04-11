#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(2e5)+10;
int n,m,b[maxn];
ll a[maxn];
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++)
		read(b[i]),m=max(m,b[i]);
	if (m==0) {
		printf("YES\n");
		for (int i=1;i<=n;i++) printf("123456789 ");
		printf("\n");
		return 0;
	}
	b[0]=b[n];
	for (int i=1;i<=n;i++)
		if (b[i]==m&&b[i-1]<m) {
			ll tmp=b[i];
			int pos=i-1; a[i]=tmp;
			if (pos==0) pos=n;
			while (pos!=i) {
				if (b[pos]==0&&tmp==b[i]) tmp+=b[i];
				else tmp+=b[pos];
				a[pos]=tmp;
				pos--;
				if (pos==0) pos=n;
			}
			printf("YES\n");
			for (int i=1;i<=n;i++) printf("%lld ",a[i]); printf("\n");
			return 0;
		}
	printf("NO\n");
	return 0;
}