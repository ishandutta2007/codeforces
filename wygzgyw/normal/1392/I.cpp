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
const double PIE=acos(-1.0);
const int maxn=(4e5)+10;
int n,m,q,a[maxn],b[maxn];
struct node {
	double re,im;
	node() {}
	node (double a,double b) : re(a),im(b) {}
	node operator + (const node &t) const {
		return node(re+t.re,im+t.im);
	}
	node operator - (const node &t) const {
		return node(re-t.re,im-t.im);
	}
	node operator * (const node &t) const {
		return node(re*t.re-im*t.im,re*t.im+im*t.re);
	}
} A[maxn],B[maxn],w[maxn];
int N,rev[maxn];
node exP(double theta) {
	return node(cos(theta),sin(theta));
}
void init(int n) {
	N=1; int lg=0;
	while (N<n) N*=2,lg++;
	for (int i=0;i<N;i++) rev[i]=0,rev[i]=(rev[i>>1]>>1)|((i&1)<<lg-1),w[i]=exP(i*PIE/N);
}
void fft(node *a,int flag) {
	if (flag==-1) reverse(a+1,a+N);
	for (int i=0;i<N;i++) if (i<rev[i]) swap(a[i],a[rev[i]]);
	for (int step=1;step<N;step<<=1) {
		for (int i=0;i<step;++i) {
			for (int k=i;k<N;k+=(step*2)) {
				int kk=k+step;
				node u=a[k],v=a[kk]*w[i*(N/step)];
				a[k]=u+v; a[kk]=u-v;
			}
		}
	}
	if (flag==-1) for (int i=0;i<N;i++) a[i].re/=N;
}
ll V[maxn],E1[maxn],E2[maxn],ans;
ll F1[maxn],F2[maxn];	
int main() {
	read(n),read(m),read(q);
	for (int i=1;i<=n;i++) read(a[i]);
	for (int i=1;i<=m;i++) read(b[i]);
	init(2e5);
	for (int i=0;i<N;i++) A[i]=B[i]=(node){0,0};
	for (int i=1;i<=n;i++) A[a[i]].re++;
	for (int i=1;i<=m;i++) B[b[i]].re++;
	fft(A,1),fft(B,1); for (int i=0;i<N;i++) A[i]=A[i]*B[i]; fft(A,-1);
	for (int i=N-1;i>=0;i--) V[i]=(ll)(A[i].re+0.5),V[i]+=V[i+1];
	
	for (int i=0;i<N;i++) A[i]=B[i]=(node){0,0};
	for (int i=1;i<=n;i++) A[a[i]].re++;
	for (int i=1;i<m;i++) B[min(b[i],b[i+1])].re++;
	fft(A,1),fft(B,1); for (int i=0;i<N;i++) A[i]=A[i]*B[i]; fft(A,-1);
	for (int i=0;i<N;i++) E1[i]=(ll)(A[i].re+0.5);
	
	for (int i=0;i<N;i++) A[i]=B[i]=(node){0,0};
	for (int i=1;i<n;i++) A[min(a[i],a[i+1])].re++;
	for (int i=1;i<=m;i++) B[b[i]].re++;
	fft(A,1),fft(B,1); for (int i=0;i<N;i++) A[i]=A[i]*B[i]; fft(A,-1);
	for (int i=N-1;i>=0;i--) E1[i]+=(ll)(A[i].re+0.5),E1[i]+=E1[i+1];
	
	for (int i=0;i<N;i++) A[i]=B[i]=(node){0,0};
	for (int i=1;i<=n;i++) A[a[i]].re++;
	for (int i=1;i<m;i++) B[max(b[i],b[i+1])].re++;
	fft(A,1),fft(B,1); for (int i=0;i<N;i++) A[i]=A[i]*B[i]; fft(A,-1);
	for (int i=0;i<N;i++) E2[i]=(ll)(A[i].re+0.5);
	
	for (int i=0;i<N;i++) A[i]=B[i]=(node){0,0};
	for (int i=1;i<n;i++) A[max(a[i],a[i+1])].re++;
	for (int i=1;i<=m;i++) B[b[i]].re++;
	fft(A,1),fft(B,1); for (int i=0;i<N;i++) A[i]=A[i]*B[i]; fft(A,-1);
	for (int i=1;i<N;i++) E2[i]+=(ll)(A[i].re+0.5),E2[i]+=E2[i-1];
	
	for (int i=0;i<N;i++) A[i]=B[i]=(node){0,0};
	for (int i=1;i<n;i++) A[min(a[i],a[i+1])].re++;
	for (int i=1;i<m;i++) B[min(b[i],b[i+1])].re++;
	fft(A,1),fft(B,1); for (int i=0;i<N;i++) A[i]=A[i]*B[i]; fft(A,-1);
	for (int i=N-1;i>=0;i--) F1[i]=(ll)(A[i].re+0.5),F1[i]+=F1[i+1];
	
	for (int i=0;i<N;i++) A[i]=B[i]=(node){0,0};
	for (int i=1;i<n;i++) A[max(a[i],a[i+1])].re++;
	for (int i=1;i<m;i++) B[max(b[i],b[i+1])].re++;
	fft(A,1),fft(B,1); for (int i=0;i<N;i++) A[i]=A[i]*B[i]; fft(A,-1);
	for (int i=1;i<N;i++) F2[i]=(ll)(A[i].re+0.5),F2[i]+=F2[i-1];
	while (q--) {
		int x; read(x);
		ll ans=V[x]-((ll)n*m-V[x]);
		ans=ans-E1[x]+E2[x-1]+F1[x]-F2[x-1];
		printf("%lld\n",ans);
	}
	return 0;
}