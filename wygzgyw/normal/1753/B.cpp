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
typedef long long ll;
const int maxn=(5e5)+10;
const int B=3;
int prime[10]={10000009,998244353,1000000007};
int jc[10][maxn],sum[10];
int n,a[maxn],x;

int main() {
	read(n);
	read(x);
	for (int i=1;i<=n;i++) {
		read(a[i]);
		if (a[i]==x) i--,n--;
	}
	if (!n) { puts("Yes"); return 0; }
	for (int i=0;i<B;i++) {
		jc[i][0]=1;
		for (int j=1;j<=500000;j++) jc[i][j]=(ll)jc[i][j-1]*j%prime[i];
		for (int j=1;j<=n;j++) sum[i]=(sum[i]+jc[i][a[j]])%prime[i];
	}
	for (int i=1;i<=n;i++) {
		int flag=1;
		for (int j=0;j<B;j++) flag&=(sum[j]==(ll)i*jc[j][x]%prime[j]);
		if (flag) { puts("Yes"); return 0; }
	}
	puts("No");
	return 0;
}