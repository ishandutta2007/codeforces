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
const int maxn=(2e5)+10;
int T,n,a[maxn],lsh[maxn],N,buc[maxn];
pair<int,int> pre[maxn],suf[maxn];
int t1,t2;
int merge(pair<int,int> A,pair<int,int> B) {
	return max(min(A.first+B.first,A.second+B.second),min(A.second+B.first,A.first+B.second));
}
int main() {
	//freopen("1.txt","r",stdin);
	read(T); while (T--) {
		read(n); N=0;
		for (int i=1;i<=n;i++) read(a[i]),lsh[++N]=a[i];
		sort(lsh+1,lsh+N+1),N=unique(lsh+1,lsh+N+1)-lsh-1;
		for (int i=1;i<=N;i++) buc[i]=0;
		for (int i=1;i<=n;i++) buc[lower_bound(lsh+1,lsh+N+1,a[i])-lsh]++;
		t1=t2=0;
		for (int i=N;i>=1;i--) {
			if (buc[i]==1) {
				if (t1<t2) t1++; else t2++;
			} else t1++,t2++;
			suf[i]=MP(t1,t2);
		}
		pre[0]=suf[N+1]=MP(0,0);
		t1=t2=0;
		for (int i=1;i<=N;i++) {
			if (buc[i]==1) {
				if (t1<t2) t1++; else t2++;
			} else t1++,t2++;
			pre[i]=MP(t1,t2);
		}
		int ans=0;
		for (int i=1;i<=N;i++) {
			ans=max(ans,merge(pre[i-1],suf[i+1])+1);
		}
		for (int i=1;i<=N;i++) {
			ans=max(ans,merge(suf[i],pre[i-1]));
		}
		printf("%d\n",ans);
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