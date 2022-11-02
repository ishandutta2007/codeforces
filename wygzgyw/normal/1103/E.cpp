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
typedef unsigned long long ull;
int n;
struct node {
	ull d[5];
	friend node operator + (node A,node B) { for (int i=0;i<5;i++) A.d[i]+=B.d[i]; return A; }
	friend node operator - (node A,node B) { for (int i=0;i<5;i++) A.d[i]-=B.d[i]; return A; }
	friend node operator * (node A,node B) {
		node C; for (int i=0;i<5;i++) C.d[i]=0;
		for (int i=0;i<5;i++) for (int j=0;j<5;j++) C.d[(i+j)%5]+=A.d[i]*B.d[j];
		return C;
	}
	void init(int flag=0) { memset(d,0,sizeof(d)); d[0]=flag; }
} a[100010],w[10],b[10];
int N=1e5;
node ksm(node A,int B) {
	node res; res.init(1);
	while (B) {
		if (B&1) res=res*A; A=A*A; B>>=1;
	} return res;
}
void FFT(int flag) {
	for (int _=0,t=1;_<5;_++,t*=10) {
		for (int i=0;i<N;i++) if ((i/t)%10==0) {
			for (int j=0;j<10;j++) b[j].init();
			for (int j=0;j<10;j++) for (int k=0;k<10;k++)
				b[j]=b[j]+a[i+t*k]*w[(flag*j*k%10+10)%10];
			for (int j=0;j<10;j++) a[i+t*j]=b[j];
		}
	}
	if (flag==-1) {
		ull iv=14757395258967641293ull;
		iv=iv*iv*iv*iv*iv;
		for (int i=0;i<n;i++) for (int j=0;j<5;j++) a[i].d[j]*=iv;
	}
}
int main() {
	read(n);
	for (int i=1;i<=n;i++) {
		int x; read(x);
		a[x].d[0]++;
	}
	w[0].init(1);
	w[1].d[3]=-1;
	for (int i=2;i<10;i++) w[i]=w[i-1]*w[1];
	FFT(1);
	for (int i=0;i<N;i++) a[i]=ksm(a[i],n);
	FFT(-1);
	for (int i=0;i<n;i++) printf("%llu\n",((a[i].d[0]-a[i].d[1])/32)%(1LL<<58));
	return 0;
}