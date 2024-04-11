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
const int maxn=(1e6)+10;
int n;
int v[maxn],c[maxn];
int rem[maxn],s1[maxn],t1,s2[maxn],t2;
int mxa[maxn*4],mxb[maxn*4],lazya[maxn*4],lazyb[maxn*4];
int tr[maxn*4];
void pushup(int root) {
	mxa[root]=max(mxa[root<<1],mxa[root<<1|1]);
	mxb[root]=max(mxb[root<<1],mxb[root<<1|1]);
	tr[root]=max(tr[root<<1],tr[root<<1|1]);
}
void puttag(int root,int delta,int flag) {
	if (!flag) {
		lazya[root]=delta;
		mxa[root]=delta;
		if (delta>mxb[root]) tr[root]=mxb[root]; else tr[root]=delta;
	} else {
		lazyb[root]=delta;
		mxb[root]=delta;
		if (delta>mxa[root]) tr[root]=mxa[root]; else tr[root]=delta;
	}
}
void pushdown(int root) {
	if (lazya[root]) puttag(root<<1,lazya[root],0),puttag(root<<1|1,lazya[root],0),lazya[root]=0;
	if (lazyb[root]) puttag(root<<1,lazyb[root],1),puttag(root<<1|1,lazyb[root],1),lazyb[root]=0;
}
void add(int L,int R,int l,int r,int root,int delta,int flag) {
	if (L<=l&&r<=R) {
		puttag(root,delta,flag); return;
	}
	int mid=(l+r)>>1; pushdown(root);
	if (L<=mid) add(L,R,l,mid,root<<1,delta,flag);
	if (mid<R) add(L,R,mid+1,r,root<<1|1,delta,flag);
	pushup(root);
}
double ANS,ans[maxn],ycl[maxn];
int lsh[maxn],N;
int id[maxn];
bool cmp(int x,int y) { return rem[x]>rem[y]; }
int main() {
	//freopen("1.txt","r",stdin);
	read(n); int k; read(k);
	for (int i=1;i<=n;i++) read(v[i]),v[i]*=100;
	for (int i=1;i<=n;i++) read(c[i]);
	s1[0]=s2[0]=n+1;
	for (int i=n;i>=1;i--) {
		while (t1&&v[s1[t1]]<v[i]) t1--;
		while (t2&&c[s2[t2]]>c[i]) t2--;
		add(i,s1[t1]-1,1,n,1,v[i],0);
		add(i,s2[t2]-1,1,n,1,c[i],1);
		s1[++t1]=i,s2[++t2]=i;
		rem[i]=tr[1];
		//printf("%d %d\n",i,rem[i]);
		lsh[++N]=rem[i]; id[i]=i;
	}
	sort(id+1,id+n+1,cmp);
	sort(lsh+1,lsh+N+1),N=unique(lsh+1,lsh+N+1)-lsh-1;
	int pos=1;
	ycl[n]=1;
	for (int i=n-1;i>=k;i--) {
		ycl[i]=ycl[i+1];
		ycl[i]/=i+1;
		ycl[i]*=i-k+1;
	}
	for (int i=N;i>=1;i--) {
		while (pos<=n&&rem[id[pos]]>=lsh[i]) pos++;
		int now=pos-1;
		ans[i]=ycl[now];
	}
	for (int i=1;i<=N;i++) ANS+=(ans[i]-ans[i+1])*lsh[i];
	printf("%.10lf\n",ANS);
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Integer overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/