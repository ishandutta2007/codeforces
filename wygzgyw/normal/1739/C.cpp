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
const int mod=998244353;
int T,C[100][100];
int n,a[110],b[110];

int main() {
	for (int i=0;i<=60;i++) {
		C[i][0]=C[i][i]=1;
		for (int j=1;j<i;j++) C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
	a[2]=1,b[2]=0;
	for (int i=4;i<=60;i++) {
		a[i]=(C[i-1][i/2]+b[i-2])%mod;
		b[i]=(C[i][i/2]-a[i]-1+mod)%mod;
	}
	read(T);
	while (T--) {
		read(n);
		printf("%d %d 1\n",a[n],b[n]);
	}
	return 0;
}