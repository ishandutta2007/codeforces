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
const int maxn=(3e5)+10;
struct Matrix {
	int d[2][2];
	friend Matrix operator * (Matrix t1,Matrix t2) {
		Matrix res;
		for (int i=0;i<2;i++) for (int j=0;j<2;j++) {
			res.d[i][j]=((ll)t1.d[i][0]*t2.d[0][j]+(ll)t1.d[i][1]*t2.d[1][j])%mod;
		}
		return res;
	}
	void init(int x) {
		d[0][0]=d[1][1]=d[0][1]=d[1][0]=0;
		d[0][0|x]++;
		d[0][0&x]++;
		d[0][0^x]++;
		d[1][1|x]++;
		d[1][1&x]++;
		d[1][1^x]++;
	}
} tr[maxn*4];
int n;
vector<int> vec[maxn];
void pushup(int root) { tr[root]=tr[root<<1]*tr[root<<1|1]; }
void build(int l,int r,int root) {
	if (l==r) { tr[root].init(0); return; }
	int mid=(l+r)>>1;
	build(l,mid,root<<1),build(mid+1,r,root<<1|1);
	pushup(root);
}
void add(int x,int l,int r,int root,int y) {
	if (l==r) { tr[root].init(y); return; }
	int mid=(l+r)>>1;
	if (x<=mid) add(x,l,mid,root<<1,y);
	else add(x,mid+1,r,root<<1|1,y);
	pushup(root);
}
int main() {
	read(n);
	for (int i=1;i<=n;i++) {
		int l,r; read(l),read(r);
		vec[l].push_back(i);
		vec[r+1].push_back(-i);
	}
	int tmp=0,ans=0;
	build(2,n,1);
	for (int i=0;i<=300001;i++) {
		for (int &x : vec[i]) {
			if (x>0) {
				if (x==1) tmp=1; else add(x,2,n,1,1);
			} else {
				if (x==-1) tmp=0; else add(-x,2,n,1,0);
			}
		}
		ans=(ans+tr[1].d[tmp][1])%mod;
	}
	printf("%d\n",ans);
	return 0;
}