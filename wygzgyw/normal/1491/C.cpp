#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=5010;
int T,n,a[maxn],b[maxn];
ll ans;
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n); ans=0;
		for (int i=1;i<=n;i++) {
			read(a[i]);
			b[i]=0;
		}
		for (int i=1,j,ori;i<=n;i++) {
			//printf("%d %d\n",i,b[i]);
			j=i+2;
			while (j<=n) {
				if (a[i]==1) break;
				b[j]++;
				if (b[i]>0) b[i]--; else ans++;
				a[i]--;
				j++;
			}
			if (a[i]>1) {
				if (b[i]<a[i]-1) ans+=a[i]-1-b[i],b[i]=0;
				else b[i]-=a[i]-1;
			}
			if (b[i]>0) b[i+1]+=b[i];
			//if (a[i]>1) ans+=a[i]-1;
			//printf("%d\n",ans);
		}
		printf("%lld\n",ans);
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