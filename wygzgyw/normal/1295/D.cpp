#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const ll INF=1e11;
int T,n;
ll a,m,ans,g,tmp,flag,d;
ll A[50],B[50];
ll gcd(ll x,ll y) {
	if (!x||!y) return x+y;
	return gcd(y,x%y);
}
ll F(ll x,ll y) { return x/y; }
ll cnt(ll x,ll i) {
	ll res=1;
	while (x%i==0) {
		x/=i; res*=i;
	} return res;
}
int main() {
//	freopen("1.txt","r",stdin);
	read(T);
	ll res;
	while (T--) {
		read(a); read(m);
		ans=0;
		g=gcd(a,m);
		n=0;
		tmp=m;
		d=1;
		for (int i=2;(ll)i*i<=tmp;i++) {
			if (tmp%i==0) {
				n++;
				A[n]=cnt(g,i);
				B[n]=A[n];
				if (B[n]>INF/i) B[n]=INF;
				else B[n]*=i;
				res=1;
				while (tmp%i==0) tmp/=i,res*=i;
				if (res==A[n]) d*=A[n],n--;
			}
		}
		if (tmp>1) {
			n++;
			A[n]=B[n]=cnt(g,tmp);
			if (B[n]>INF/tmp) B[n]=INF;
			else B[n]*=tmp;
			if (tmp==A[n]) d*=A[n],n--;
		}
		
		//for (int i=1;i<=n;i++) printf("%lld %lld\n",A[i],B[i]);
		for (int t=0;t<(1<<n);t++) {
			g=d;
			flag=1;
			for (int i=1;i<=n;i++)
				if (t&(1<<(i-1))) {
					if (g>INF/A[i]) g=INF;
					else g*=A[i];
				} else {
					flag*=-1;
					if (g>INF/B[i]) g=INF;
					else g*=B[i];
				}
			if (g==INF) continue;
		//	printf(" %d %lld\n",flag,g);
			flag*=F(a+m-1,g)-F(a-1,g);
		//	printf("%lld\n",flag);
			ans+=flag;
		}
		printf("%lld\n",ans);
	}
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