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
const int maxn=510;
int T,n;
int a[maxn],b[maxn];
vector<pair<int,int> > ans;
void solve(int l,int r) {
	ans.push_back(MP(l,r));
	reverse(a+l,a+r+1);
	//printf("l=%d,r=%d\n",l,r);
	assert(a[l]==a[r]);
}
bool solve() {
	for (int i=2;i<=n;i++) {
		if (a[i]!=b[i]) {
			int f1=0,f2=0;
			for (int j=i;j<n;j++) {
				if (b[i-1]==a[j]&&b[i]==a[j+1]) { f1=j; }
				if (b[i-1]==a[j+1]&&b[i]==a[j]) { f2=j; }
			}
		/*	printf("i=%d,f1=%d,f2=%d\n",i,f1,f2);
			if (i==19) {
				for (int i=1;i<=n;i++) printf("%d ",a[i]); puts("");
				for (int i=1;i<=n;i++) printf("%d ",b[i]); puts("");
			}*/
			if (!f1&&!f2) return 0;
			if (!f2) {
				int fd=0;
				for (int k=f1;k>=i;k--) {
					for (int l=f1+1;l<=n;l++) if (a[k]==a[l]) { solve(k,l); i--; fd=1; goto H; }
				}
				if (!fd) return 0;
				H:;
			} else {
				solve(i-1,f2+1);
				assert(a[i]==b[i]);
			}
		}
	}
	return 1;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	int C=0;
	for (int j=1;j<=T;j++) {
		C++;
		read(n); ans.clear();
		for (int i=1;i<=n;i++) read(a[i]);
		for (int i=1;i<=n;i++) read(b[i]);
		/*if (C==73) {
			for (int i=1;i<=n;i++) printf("%d ",a[i]); puts("");
			for (int i=1;i<=n;i++) printf("%d ",b[i]); puts("");
		} else continue;*/
		if (a[1]!=b[1]||a[n]!=b[n]) { puts("NO"); continue; }
		if (solve()) {
			puts("YES"); printf("%d\n",(int)ans.size());
			for (auto [l,r] : ans) printf("%d %d\n",l,r);
			for (int i=1;i<=n;i++) assert(a[i]==b[i]);
		} else {
			//cerr<<C<<endl;
			puts("NO");//assert(0);
		}
		
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