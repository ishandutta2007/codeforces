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
const double PIE=acos(-1.0);
const int maxn=9e4;
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
} A[maxn],B[55][maxn],w[maxn];
int N,n,m,t,X,rev[maxn];
node exP(double theta) {
	return node(cos(theta),sin(theta));
}
void init(int n) {
	N=1; int lg=0;
	while (N<n) N*=2,lg++;
	for (int i=0;i<N;i++) rev[i]=0,rev[i]=(rev[i>>1]>>1)|((i&1)<<lg-1),w[i]=exP(i*PIE/N);
}
node tmp[maxn];
void fft(node *a) {
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
}
struct edge {
	int x,y,c; double p[20010];
} E[110];
double ans[55][20010];
double tot[110][20010];
int dis[55][55];
int INF=1e9;
int flag=0;
void dfs(int l,int r) {
	if (l==r) {
		if (l==0) return;
		for (int i=1;i<=m;i++) {
			int x=E[i].x,y=E[i].y;
			ans[x][l]=min(ans[x][l],tot[i][l]);
		}
		return;
	}
	int mid=(l+r)>>1;
	dfs(l,mid);
	init(r-l+mid-l+4);
	for (int i=1;i<=n;i++) {
		for (int j=0;j<N;j++) B[i][j]=(node){0,0};
		for (int j=l;j<=mid;j++) B[i][j-l].re=ans[i][j];
		fft(B[i]);
	}
	for (int i=1;i<=m;i++) {
		int x=E[i].x,y=E[i].y;
		if (r-l+1<=100) {
			for (int k=mid+1;k<=r;k++) {
				for (int j=l;j<=mid;j++) 
					tot[i][k]+=E[i].p[k-j]*ans[y][j];
			}
			continue;
		}
		for (int j=0;j<N;j++) A[j]=(node){0,0};
		for (int j=1;j<=r-l;j++) A[j]=(node){E[i].p[j],0};
		fft(A);
		for (int j=0;j<N;j++) A[j]=A[j]*B[y][j];
		reverse(A+1,A+N);
		fft(A);
		for (int k=mid+1;k<=r;k++) tot[i][k]+=A[k-l].re/N;
	}
	dfs(mid+1,r);
}
double suf[20010];
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(m),read(t),read(X);
	for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) if (i!=j) dis[i][j]=INF;
	for (int i=1;i<=m;i++) {
		read(E[i].x),read(E[i].y),read(E[i].c);
		dis[E[i].x][E[i].y]=E[i].c;
		for (int j=1;j<=t;j++) read(E[i].p[j]),E[i].p[j]/=100000,tot[i][j]=E[i].c;
	}
	for (int k=1;k<=n;k++) for (int i=1;i<=n;i++) for (int j=1;j<=n;j++)
		dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	for (int i=1;i<n;i++) {
		ans[i][0]=dis[i][n]+X;
		for (int j=1;j<=t;j++) ans[i][j]=1e9;
	}
	for (int i=1;i<=m;i++) {
		int x=E[i].x,y=E[i].y;
		for (int k=t;k>=1;k--) suf[k]=suf[k+1]+E[i].p[k];
		for (int j=1;j<=t;j++) {
			tot[i][j]+=suf[j+1]*(y<n?ans[y][0]:X);
		}
	}
	dfs(0,t);
	printf("%.8lf\n",ans[1][t]);
	return 0;
}