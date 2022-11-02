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
const int maxn=(1e6)+10;
int n; ll a[maxn],ans;
int b[maxn];
int s1[maxn],t1,s2[maxn],t2,all;
struct BIT {
ll s1[maxn],s2[maxn];
void add(int x,int delta) {
	for (int i=x;i<=n;i+=i&(-i)) s1[i]+=delta,s2[i]+=delta*x;
}
void add(int l,int r,int delta) {
	add(l,delta),add(r+1,-delta);
}
ll query(int x) {
	ll res=0; for (int i=x;i;i-=i&(-i)) res+=s1[i]*(x+1)-s2[i];
    return res;
}
ll query(int l,int r) { return query(r)-query(l-1); }
void init() { for (int i=1;i<=n;i++) s1[i]=s2[i]=0; }
} T[2];
void add(int l,int r,int x) {
	all+=T[x^1].query(l,r);
	T[x].add(l,r,1);
}
void del(int l,int r,int x) {
	all-=T[x^1].query(l,r);
	T[x].add(l,r,-1);
} bool buc[100];
int main() {
	read(n); int mx=0;
	for (int i=1;i<=n;i++) read(a[i]),b[i]=__builtin_popcountll(a[i]),mx=max(mx,b[i]),buc[b[i]]=1;
	for (int p=0;p<=mx;p++) if (buc[p]) {
		t1=t2=0; s1[0]=s2[0]=n+1; T[0].init(),T[1].init(); all=0;
		for (int i=n;i>=1;i--) {
			while (t1&&a[s1[t1]]<a[i]) {
				if (b[s1[t1]]==p) del(s1[t1],s1[t1-1]-1,0);
				t1--;
			}
			s1[++t1]=i;
			if (b[i]==p) add(i,s1[t1-1]-1,0);
			while (t2&&a[s2[t2]]>a[i]) {
				if (b[s2[t2]]==p) del(s2[t2],s2[t2-1]-1,1);
				t2--;
			}
			s2[++t2]=i;
			if (b[i]==p) add(i,s2[t2-1]-1,1);
			ans+=all;
		}
	}
	printf("%lld\n",ans);
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