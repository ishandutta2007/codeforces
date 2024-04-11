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
const int maxn=1010;
int n,a[maxn],c0,ans;
int lsh[maxn],N,cnt[maxn];
vector<int> V;
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++) {
		read(a[i]);
		lsh[++N]=a[i];
		if (a[i]==0) c0++;
	}
	ans=max(2,c0);
	sort(lsh+1,lsh+N+1),N=unique(lsh+1,lsh+N+1)-lsh-1;
	for (int i=1;i<=n;i++) cnt[lower_bound(lsh+1,lsh+N+1,a[i])-lsh]++;
	for (int i=1;i<=N;i++) for (int j=1;j<=N;j++) {
		ll x=lsh[i],y=lsh[j];
		if (i==j&&cnt[i]==1) continue;
		if (!x&&!y) continue;
		V.clear();
		V.push_back(i),V.push_back(j),cnt[i]--,cnt[j]--;
		while (1) {
			ll z=x+y;
			int pos=lower_bound(lsh+1,lsh+N+1,z)-lsh;
			if (lsh[pos]!=z||cnt[pos]==0) break;
			cnt[pos]--; x=y,y=z; V.push_back(pos);
		}
		ans=max(ans,(int)V.size());
		for (int &x : V) cnt[x]++;
	}
	printf("%d\n",ans);
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