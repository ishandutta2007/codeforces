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
const int maxn=210;
int n,k;
struct node {
	ll x,y;
	friend node operator - (node A,node B) { return (node){A.x-B.x,A.y-B.y}; }
	friend ll operator * (node A,node B) { return abs(A.x*B.y-A.y*B.x); }
} p[maxn];
pair<int,ll> f[maxn][maxn];
ll S(int i,int j,int k) {
	return (p[j]-p[i])*(p[k]-p[i]);
}
bool check(ll mid) {
	for (int len=3;len<=n;len++)
	for (int i=1,j=len;j<=n;i++,j++) {
		f[i][j]=MP(0,0);
		for (int k=i+1;k<j;k++) {
			pair<int,ll> tmp=MP(f[i][k].first+f[k][j].first,f[i][k].second+f[k][j].second+S(i,k,j));
			if (tmp.second>=mid) tmp.second=0,tmp.first++;
			f[i][j]=max(f[i][j],tmp);
		}
	}
	return f[1][n].first>k;
}
int main() {
	read(n),read(k);
	for (int i=1;i<=n;i++) read(p[i].x),read(p[i].y);
	ll l=0,r=1e18,res,mid;
	while (l<=r) {
		mid=(l+r)>>1;
		if (check(mid)) res=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%lld\n",res);
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