#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(2e7)+10;
int T,cnt[maxn];
ll c,d,x,ans;
void insert(ll i) {
	if ((x+d*i)%(c*i)==0) ans+=1LL<<cnt[(x+d*i)/(c*i)];
}
int main() {
	//freopen("1.txt","r",stdin);
	for (int i=2;i<maxn;i++) if (cnt[i]==0) {
		for (int j=i;j<maxn;j+=i) cnt[j]++;
	}
	read(T);
	while (T--) {
		read(c),read(d),read(x);
		ans=0;
		for (ll i=1;i*i<=x;i++) if (x%i==0) {
			insert(i);
			if (x/i!=i) insert(x/i);
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