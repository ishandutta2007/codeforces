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
const int maxn=2010;
int T,n;
char s[maxn];
int d[maxn][maxn];
int L[maxn],R[maxn];
int findL(int x) { if (L[x]==x) return x; return L[x]=findL(L[x]); }
int findR(int x) { if (R[x]==x) return x; return R[x]=findR(R[x]); }
vector<pair<int,int> > ans;
void link(int x,int y) {
	ans.push_back(MP(x,y));
}
int main() {
	//freopen("1.txt","r",stdin);
	read(T); while (T--) {
		read(n);
		for (int i=1;i<=n;i++) {
			scanf("%s",s+1);
			L[i]=R[i]=i;
			for (int j=i;j<=n;j++) if (s[j-i+1]=='1') d[i][j]=1; else d[i][j]=0;
		}
		ans.clear();
		for (int len=2;len<=n;len++) for (int l=1,r=len;r<=n;l++,r++) if (d[l][r]) {
			if (findR(l)>=r) continue;
			int x=findR(l); x++;
			vector<int> A,B;
			A.push_back(l),B.push_back(r);
			int op=0;
			while (findR(x)<r) {
				if (!op) B.push_back(x); else A.push_back(x); op^=1;
				x=findR(x)+1;
			}
			link(l,r);
			for (int i=1;i<A.size();i++) link(A[i-1],A[i]);
			for (int i=1;i<B.size();i++) link(B[i-1],B[i]);
			for (int i=l;i<=r;i++) R[findR(i)]=findR(r);
		}
		for (pair<int,int> &A : ans) printf("%d %d\n",A.first,A.second);
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