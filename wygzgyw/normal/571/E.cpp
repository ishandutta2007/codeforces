#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const ll mod=(1e9)+7;
const ll M=998244353;
const double eps=1e-6;
int n,cnt[110];
ll a[110],b[110],w[110],B[110],tmp;
void No() { printf("-1\n"); exit(0); }
int lg(ll x) { return (int)ceil(log(1.0*x)/log(2.0)); }
ll ksm(ll x,ll y) {
	ll res=1;
	while (y) {
		if (y&1) res=res*x%mod;
		x=x*x%mod; y>>=1;
	} return res;
}
ll gcd(ll x,ll y) {
	if (!x||!y) return x+y;
	return gcd(y,x%y);
}
void solve1(int x) {
	for (int i=1;i<=n;i++) {
		if (b[i]==1&&a[i]!=a[x]) No();
		if (b[i]>1) {
			tmp=a[i];
			while (1) {
				if (tmp>a[x]/b[i]) No();
				tmp*=b[i];
				if (tmp==a[x]) break;
			}
		}
	}
	printf("%lld\n",a[x]);
	exit(0);
}
void solve2(int x) {
	ll t1=a[1]%M,t2,t3;
	int num=-1;
	for (int i=0;i<400;i++) {
		t2=a[x]%M;
		for (int j=0;j<400;j++) {
			if (t1==t2) {
				t3=t1,num=i;
				break;
			}
			t2=t2*b[x]%M;
		}
		if (num!=-1) break;
		t1=t1*b[1]%M;
	}
	if (num==-1) No();
	bool flag;
	for (int i=1;i<=n;i++) {
		t1=a[i]%M;
		flag=0;
		for (int j=0;j<=100000;j++) {
			if (t1==t3) { flag=1; break; }
			t1=t1*b[i]%M;
		}
		if (!flag) No();
	}
	tmp=a[1];
	while (num--) tmp=tmp*b[1]%mod;
	printf("%lld\n",tmp);
	exit(0);
}
int main() {
	//freopen("1.txt","r",stdin);
	srand(time(0));
	read(n);
	for (int i=1;i<=n;i++) read(a[i]),read(b[i]);
	for (int i=1;i<=n;i++)
		if (b[i]==1) solve1(i);
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=lg(b[i]);j++) {
			tmp=(ll)floor(pow(b[i],1.0/j)+0.5);
			if (fabs(pow(tmp,j)-b[i])<eps) B[i]=j,w[i]=tmp;
		}
	}
	for (int i=2;i<=n;i++)
		if (w[i]!=w[1]) solve2(i);
	int mx=0;
	for (int i=1;i<=n;i++) {
		while (a[i]%w[i]==0) a[i]/=w[i],cnt[i]++;
		mx=max(mx,cnt[i]);
	}
	for (int i=2;i<=n;i++)
		if (a[i]!=a[1]) No();
	ll Lcm=B[1],z,ans=cnt[1];
	bool flag=1;
	for (int i=2;i<=n;i++) {
		flag=0;
		for (int j=0;j<B[i];j++)
			if ((ans+Lcm*j)%B[i]==cnt[i]%B[i]) {
				ans+=Lcm*j; flag=1; break;
			}
		if (!flag) No();
		z=gcd(Lcm,B[i]);
		Lcm=Lcm/z*B[i];
	}
	while (ans<mx) ans+=Lcm;
	printf("%lld\n",a[1]*ksm(w[1],ans)%mod);
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