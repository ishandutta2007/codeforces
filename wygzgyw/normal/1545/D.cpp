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
int m,k,a[5010][1010];
ll sum[5010],s2[5010];
int ans1; ll ans2;
pair<ll,ll> ans[5010];

int main() {
	//freopen("1.txt","r",stdin);
	read(m),read(k);
	for (int i=0;i<k;i++) {
		for (int j=1;j<=m;j++) {
			read(a[i][j]);
			sum[i]+=a[i][j];
			s2[i]+=(ll)a[i][j]*a[i][j];
		}
	//	printf("%lld\n",sum[i]);
	}
	ll sv=(sum[k-1]-sum[0])/(k-1);
	ll A=(s2[k-1]-s2[0])/(k-1),B,S1,S2;
	
	for (int i=1;i<k;i++)
		if (sum[i]!=sum[0]+i*sv) { ans1=i; break; }
	for (int i=1;i<k;i++) if (i!=ans1) {
		B=(s2[i]-s2[0])/i;
		S2=(A-B)/(k-1-i);
		S1=B-i*S2;
		assert(S1+(k-1)*S2==A);
		break;
	}
	
	for (int j=1;j<=m;j++) {
		ll x=a[ans1][j],y=sum[ans1]-x-sum[0]-ans1*sv; y=-y;
		if ((S1+ans1*S2)*ans1==(s2[ans1]-x*x+y*y-s2[0])) { ans2=y; }
	}
	printf("%d %lld\n",ans1,ans2);
	fflush(stdout);
	
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