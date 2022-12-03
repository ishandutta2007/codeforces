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
const int maxn=(2e5)+10;
int T,n,m;
int a[maxn],ans;
int p[15],tot;
int main() {
	read(T);
	while (T--) {
		read(n),read(m);
		for (int i=1;i<=n;i++) read(a[i]);
		ans=1;
		for (int i=1;i<n;i++) if (a[i]%a[i+1]!=0) { ans=0; break; }
		if (!ans) { puts("0"); continue; }
		int x=a[1]; vector<int> P;
		for (int i=2;(ll)i*i<=x;i++) if (x%i==0) {
			while (x%i==0) x/=i;
			P.push_back(i);
		}
		if (x>1) P.push_back(x);
		for (int i=2;i<=n;i++) {
			ll cnt=0;
			if (a[i]==a[i-1]) cnt=(m/a[i]);
			else {
				int bd=m/a[i];
				int x=a[i-1]/a[i];
				tot=0;
				for (int &p : P) if (x%p==0) ::p[++tot]=p;
				for (int t=0;t<(1<<tot);t++) {
					int mul=1,flag=0;
					for (int j=0;j<tot;j++) if (t>>j&1) mul*=p[j+1],flag^=1;
					if (flag) cnt-=bd/mul; else cnt+=bd/mul;
				}
			}
			ans=(ll)ans*cnt%mod;
		}
		printf("%d\n",ans);
	}
	return 0;
}