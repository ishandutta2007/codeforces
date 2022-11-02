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
const int INF=(2e9)+1;
int T,n,ans;
int mn,mx,a,b;
int l,r,c;
map<pair<int,int>,int> M;
void chkmin(int &x,int y) { if (x>y) x=y; }
int main() {
	read(T);
	while (T--) {
		read(n); M.clear();
		for (int i=1;i<=n;i++) {
			read(l),read(r),read(c);
			if (M.find(MP(l,r))!=M.end()) chkmin(M[MP(l,r)],c);
			else M[MP(l,r)]=c;
			if (i==1) mn=l,mx=r,a=b=c;
			else {
				if (l<mn) mn=l,a=c; else if (l==mn) a=min(a,c);
				if (r>mx) mx=r,b=c; else if (r==mx) b=min(b,c);
			}
			if (M.find(MP(mn,mx))!=M.end()) ans=M[MP(mn,mx)]; else ans=INF;
			ans=min(ans,a+b);
			printf("%d\n",ans);
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