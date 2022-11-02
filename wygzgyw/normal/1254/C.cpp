#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=1010;
int n,t1,t2,tot,ans[maxn];
struct node {
	int id; ll x;
} a[maxn],b[maxn],c[maxn],d[maxn];
bool cmp(node x,node y) { return x.x<y.x; }
int c1,c2;
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	int op; ll x;
	for (int i=3;i<=n;i++) {
		printf("2 1 2 %d\n",i);
		fflush(stdout);
		read(op);
		printf("1 1 2 %d\n",i);
		fflush(stdout);
		read(x);
		if (op<0) a[++t1]=(node){i,x};
		else b[++t2]=(node){i,x};
	}
	ans[tot=1]=1;
	if (t1) {
		sort(a+1,a+t1+1,cmp);
		for (int i=1;i<t1;i++) {
			printf("2 1 %d %d\n",a[t1].id,a[i].id);
			fflush(stdout);
			read(op);
			if (op<0) c[++c1]=a[i];
			else d[++c2]=a[i];
		}
		for (int i=1;i<=c1;i++) ans[++tot]=c[i].id;
		ans[++tot]=a[t1].id;
		reverse(d+1,d+c2+1);
		for (int i=1;i<=c2;i++) ans[++tot]=d[i].id;
	}
	ans[++tot]=2;
	if (t2) {
		c1=c2=0;
		sort(b+1,b+t2+1,cmp);
		for (int i=1;i<t2;i++) {
			printf("2 2 %d %d\n",b[t2].id,b[i].id);
			fflush(stdout);
			read(op);
			if (op<0) c[++c1]=b[i];
			else d[++c2]=b[i];
		}
		for (int i=1;i<=c1;i++) ans[++tot]=c[i].id;
		ans[++tot]=b[t2].id;
		reverse(d+1,d+c2+1);
		for (int i=1;i<=c2;i++) ans[++tot]=d[i].id;
	}
	printf("0 ");
	for (int i=1;i<=n;i++) printf("%d ",ans[i]);
	printf("\n");
	fflush(stdout);
	return 0;
}
/*
  REMEMBER:
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Array size? Integer overflow? Time complexity? Memory usage? Precision error?
*/