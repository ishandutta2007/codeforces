#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int mod=998244353;
const int maxn=1510*20;
int n,fa[maxn],tot,sz[maxn],cnt[maxn];
typedef vector<int> poly;
poly dp[maxn];
struct edge { int x,y,z; } d[7000010];
bool cmp(edge A,edge B) { return A.z<B.z; }
int find(int x) {
	if (fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
int ksm(int x,int y) {
	int res=1;
	while (y) {
		if (y&1) res=(ll)res*x%mod;
		x=(ll)x*x%mod; y>>=1;
	}
	return res;
}
int t1[maxn],t2[maxn];
int ycl[maxn],ycr[maxn],IV;
int N,rev[maxn];
int iv[maxn],ivjc[maxn],jc[maxn];
void init(int n) {
    N=1; int lg=0;
    while (N<n) N*=2,lg++;
    for (int i=0;i<N;i++)
    	rev[i]=(rev[i>>1]>>1)|((i&1)<<(lg-1));
    IV=ksm(N,mod-2);
    for (int step=1;step<N;step*=2) {
        ycl[step]=ksm(3,(mod-1)/(step*2));
        ycr[step]=ksm(ycl[step],mod-2);
    }
}
void fft(int *a,int flag) {
    for (int i=0;i<N;i++)
    	if (i<rev[i]) swap(a[i],a[rev[i]]);
    for (int step=1;step<N;step*=2) {
        int wn=ycl[step];
        if (flag==-1) wn=ycr[step];
        for (int i=0;i<N;i+=step*2) {
            int w=1;
            for (int k=i;k<i+step;k++) {
                int u=a[k],v=(ll)a[k+step]*w%mod;
                a[k]=(u+v)%mod; a[k+step]=(u-v+mod)%mod;
                w=(ll)w*wn%mod;
            }
        }
    }
    if (flag==-1) {
        for (int i=0;i<N;i++)
            a[i]=(ll)a[i]*IV%mod;
    }
}
poly operator * (poly A,poly B) {
	int n=(int)A.size(),m=(int)B.size();
	init(n+m+2);
	for (int i=0;i<n;i++) t1[i]=A[i]; for (int i=n;i<N;i++) t1[i]=0;
	for (int i=0;i<m;i++) t2[i]=B[i]; for (int i=m;i<N;i++) t2[i]=0;
	fft(t1,1); fft(t2,1);
	for (int i=0;i<N;i++) t1[i]=(ll)t1[i]*t2[i]%mod;
	fft(t1,-1);
	poly C; C.resize(n+m);
	for (int i=0;i<n+m;i++) C[i]=t1[i];
	return C;
}
void print(poly A) {
	for (int i=0;i<A.size();i++) printf("%d ",A[i]);
	printf("\n");
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	int x,y,z;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++) {
		read(z);
		if (i<j) d[++tot]=(edge){i,j,z};
	}
	sort(d+1,d+tot+1,cmp);
	for (int i=1;i<=n;i++) {
		fa[i]=i; sz[i]=1;
		dp[i].resize(2),dp[i][1]=1;
	}
	for (int i=1;i<=tot;i++) {
		x=find(d[i].x),y=find(d[i].y);
		//printf("x=%d y=%d\n",x,y);
		if (x==y) {
			cnt[x]++;
			if (cnt[x]==sz[x]*(sz[x]-1)/2) dp[x][1]=(dp[x][1]+1)%mod;//,printf("? %d\n",x);
		} else {
			fa[x]=y; sz[y]+=sz[x]; cnt[y]+=cnt[x]+1;
			//print(dp[y]),print(dp[x]);
			dp[y]=dp[y]*dp[x];
			//print(dp[y]);
			if (cnt[y]==sz[y]*(sz[y]-1)/2) dp[y][1]=(dp[y][1]+1)%mod;//,printf("? %d\n",x);
			//exit(0);
		}
	}
	x=find(1);
	for (int i=1;i<=n;i++) printf("%d ",dp[x][i]); printf("\n");
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Interger overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/