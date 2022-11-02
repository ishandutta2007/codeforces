#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
int T,m,cnt[70];
ll n,x,s,ans;
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n); read(m);
		memset(cnt,0,sizeof(cnt));
		s=0;
		while (m--) {
			read(x); s+=x;
			for (int i=0;;i++)
				if ((1LL<<i)==x) {
					cnt[i]++; break;
				}
		}
		if (s<n) { printf("-1\n"); continue; }
		ans=0;
		for (int i=0;n;i++) {
			if (n&(1LL<<i)) {
				int j;
				for (j=i;;j++)
					if (cnt[j]) break;
				for (;j>i;j--)
					cnt[j]--,cnt[j-1]+=2,ans++;
				cnt[i]--;
				n-=1LL<<i;
			}
			cnt[i+1]+=cnt[i]/2;
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