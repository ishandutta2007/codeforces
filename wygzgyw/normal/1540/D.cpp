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
const int maxn=(1e5)+10;
const int INF=1e9;
const int block=200;
int n,tot,bel[maxn],b[maxn],q;
namespace xyr {
	int tr[maxn];
	void add(int x,int delta) {
		for (;x<=n;x+=x&(-x)) tr[x]+=delta;
	}
	int Find(int x) {
		int res=0,sum=0;
		for (int i=17;i>=0;i--)
			if (res+(1<<i)<=n&&sum+tr[res+(1<<i)]<x) res+=(1<<i),sum+=tr[res];
		return res+1;
	}
	int query(int x) {
		int res=0; for (;x;x-=x&(-x)) res+=tr[x]; return res;
	}
};
struct Block {
	int l,r,cnt;
	int A[block+10],B[block+10];
	vector<int> d;
	void init() {
		cnt=0; d.clear();
		for (int i=l;i<=r;i++) {
			if (xyr::query(n)<b[i]) continue;
			int x=xyr::Find(b[i]);
			d.push_back(x);
			xyr::add(x,1);
		}
		sort(d.begin(),d.end());
		int rem=0;
		for (int i=0;i<d.size();i++) {
			rem++;
			if (i==(int)d.size()-1||d[i]!=d[i+1]) A[++cnt]=d[i],B[cnt]=rem;
		}
		for (int x : d) xyr::add(x,-1);
	}
	int query(int now) {
		int pos=upper_bound(A+1,A+cnt+1,now)-A-1;
		return now+B[pos];
		
	}
} st[maxn/block+5];

int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++) read(b[i]),b[i]=i-b[i];
	for (int i=1;i<=n;i++) xyr::add(i,1);
	for (int l=1,r;l<=n;l=r+1) {
		r=min(n,l+block-1);
		tot++; st[tot].l=l,st[tot].r=r;
		for (int i=l;i<=r;i++) bel[i]=tot;
		st[tot].init();
	} read(q);
	int op,x;
	while (q--) {
		read(op),read(x);
		if (op==1) {
			read(b[x]),b[x]=x-b[x];
			st[bel[x]].init();
		} else {
			int now=b[x];
			//for (int i=1;i<=n;i++) printf("%d ",b[i]); puts("");
			for (int i=x+1;i<=st[bel[x]].r;i++) {
				if (now>=b[i]) now++;
			}
			//printf("now=%d\n",now);
			for (int i=bel[x]+1;i<=tot;i++) {
				now=st[i].query(now);
			//printf("now=%d\n",now);
			}
			printf("%d\n",now);
		}
	}
	
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