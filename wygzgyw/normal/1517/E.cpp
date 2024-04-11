#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int mod=998244353;
const int maxn=(2e5)+10;
int T,n,a[maxn],ans;
ll sum,s0[maxn],s1[maxn];
void update(int &x,int y) { x+=y; if (x>=mod) x-=mod; }
void solve(int L,int R,int cur) {
	s0[L-1]=s1[L-1]=0;
	for (int i=L;i<=R;i++) {
		s0[i]=s0[i-1],s1[i]=s1[i-1];
		if (i&1) s1[i]+=a[i];
		else s0[i]+=a[i];
	}
	s0[R+1]=s1[R+1]=0;
	int l,r,res,mid;
	ll now=cur,tmp;
	for (int i=L;i<=R;i++) {
		now+=a[i];
		if (now>sum) break;
		l=i,r=R-1,res=-1;
		while (l<=r) {
			mid=(l+r)>>1;
			if (i&1) tmp=s1[mid]-s1[i];
			else tmp=s0[mid]-s0[i];
			if (tmp+now<=sum) res=mid,l=mid+1;
			else r=mid-1;
		}
		
		//printf("%d %d\n",i,res);
		if (res!=-1) {
			if (res%2!=i%2) res--;
			update(ans,(res-i)/2+1);
		}
	}
	
}
int p[30],c[30],tp,tc;
bool check() {
	for (int i=2;i<tp;i++)
		if (p[i]-p[i-1]<p[i+1]-p[i]) return 0;
	for (int i=2;i<tc;i++)
		if (c[i]-c[i-1]>c[i+1]-c[i]) return 0;
	return 1;
}
void solve1() {
	ans=0;
	for (int t=0;t<(1<<n);t++) {
		tp=tc=0;
		ll sc=0,sp=0;
		for (int i=1;i<=n;i++) {
			if (t&(1<<(i-1))) p[++tp]=i,sp+=a[i];
			else c[++tc]=i,sc+=a[i];
		}
		if (check()) {
			if (sc<sp) ans++;
		}
	}
	printf("%d\n",ans);
}
int main() {
//	freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n);
		ans=1,sum=0;
		for (int i=1;i<=n;i++) read(a[i]),sum+=a[i];
		if (n<=5) { solve1(); continue; }
		if (sum&1) sum/=2;
		else sum=sum/2-1;
		solve(2,n-1,a[n]);
		solve(1,n-1,a[n]);
		solve(2,n,0);
		solve(1,n,0);
		//printf("%d\n",ans);
		ll now=0;
		for (int i=n;i>=1;i--) {
			now+=a[i];
			if (now<=sum) update(ans,1);
		}
		printf("%d\n",ans);
	}
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