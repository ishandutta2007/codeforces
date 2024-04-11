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
const int maxn=1010;
int n;
int p[maxn],q[maxn],tot;
vector<vector<int> > ans;
void solve(vector<int> &V) {
	ans.push_back(V);
	vector<pair<int,int> > inter;
	int fst=0;
	for (int &x : V) {
		inter.push_back(MP(fst+1,fst+x));
		fst+=x;
	}
	reverse(inter.begin(),inter.end());
	int tot=0;
	for (auto [x,y] : inter) for (int i=x;i<=y;i++) q[++tot]=p[i];
	swap(p,q);
}

int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++) read(p[i]);
	while (1) {
		int fd=0;
		for (int i=n;i>=1;i--) if (p[i]!=i) { fd=i; break; }
		if (!fd) break;
		int f2=0;
		for (int i=1;i<=n;i++) if (p[i]==p[fd]+1) { f2=i; break; }
		vector<int> V;
		if (f2>1) V.push_back(f2-1);
		int f3=1;
		for (int i=f2+1;i<=n;i++) if (p[i]>p[i-1]) f3++; else break;
		V.push_back(f3);
		V.push_back(fd-f2-f3+1);
		if (fd<n) V.push_back(n-fd);
		solve(V);
		//for (int &x : V) printf("%d ",x); puts("");
		//for (int i=1;i<=n;i++) printf("%d ",p[i]); puts("");
	}
	printf("%d\n",(int)ans.size());
	for (auto A : ans) {
		printf("%d ",(int)A.size());
		for (int &x : A) printf("%d ",x); puts("");
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