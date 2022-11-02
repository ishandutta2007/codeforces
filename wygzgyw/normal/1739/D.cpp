// wygzgyw
#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
template <typename T> void write(T t) {
	if (t<0) { putchar('-'); write(-t); return; }
	if (t>9) write(t/10);
	putchar('0'+t%10);
}
template <typename T> void writeln(T t) { write(t); puts(""); }
#define MP make_pair
const int maxn=(2e5)+10;
int T;
int n,k,p[maxn];
int f[maxn];
bool check(int mid) {
	int res=0;
	for (int i=1;i<=n;i++) f[i]=0;
	for (int i=n;i>=2;i--) {
		if (f[i]==mid-1&&p[i]!=1) res++;
		else f[p[i]]=max(f[p[i]],f[i]+1);
	}
	return res<=k;
}
int main() {
	read(T);
	while (T--) {
		read(n); read(k);
		for (int i=2;i<=n;i++) read(p[i]);
		int l=1,r=n-1,mid,res;
		while (l<=r) {
			mid=(l+r)>>1;
			if (check(mid)) res=mid,r=mid-1; else l=mid+1;
		}
		printf("%d\n",res);
	}
	return 0;
}