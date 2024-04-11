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
int T,n,k,a[maxn];
map<int,int> M;
int buc[maxn],tot,pre[maxn];
pair<int,int> d[maxn];
int tr[maxn*4],cnt[maxn*4];
void add(int x,int l,int r,int root) {
	if (l==r) {
		tr[root]+=x,cnt[root]++; return;
	}
	int mid=(l+r)>>1;
	if (x<=mid) add(x,l,mid,root<<1);
	else add(x,mid+1,r,root<<1|1);
	tr[root]=tr[root<<1]+tr[root<<1|1];
	cnt[root]=cnt[root<<1]+cnt[root<<1|1];
}
int query(int k,int l,int r,int root) {
	if (l==r) {
		k=min(k,tr[root]);
		return k/l;
	}
	int mid=(l+r)>>1;
	if (k>=tr[root<<1]) return cnt[root<<1]+query(k-tr[root<<1],mid+1,r,root<<1|1);
	return query(k,l,mid,root<<1);
}
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n),read(k); M.clear();
		for (int i=0;i<=n;i++) buc[i]=0;
		for (int i=1;i<=n;i++) {
			read(a[i]);
			if (a[i]<=n) buc[a[i]]++;
			M[a[i]]++;
		}
		tot=0;
		for (auto [x,y] : M) d[++tot]=MP(x,y);
		for (int i=0;i<n;i++) {
			pre[i]=(i==0?0:pre[i-1])+(buc[i]==0);
		}
		for (int i=1;i<=n*4;i++) tr[i]=cnt[i]=0;
		int pos=tot,ans=1e9;
		for (int i=n-1;i>=-1;i--) {
			while (pos&&d[pos].first>i) {
				add(d[pos].second,1,n,1);
				pos--;
			}
			if (i==-1||pre[i]<=k) ans=min(ans,i+1+(tot-pos)-query(k,1,n,1)-(i+1));
		}
		printf("%d\n",ans);
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