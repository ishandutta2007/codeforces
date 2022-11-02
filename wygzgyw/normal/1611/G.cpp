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
const int maxn=(1e6)+10;
int n,m;
char s[maxn];
vector<pair<int,int> > A,B; int mn;
namespace BIT {
int tr[maxn*4];
void clear() {
	for (int i=0;i<=max(n,m)*4;i++) tr[i]=0;
}
void add(int x,int delta) {
	x-=mn; for (;x;x-=x&(-x)) tr[x]=max(tr[x],delta);
}
int query(int x) {
	x-=mn; int res=0; for (;x<=max(n,m)*4;x+=x&(-x)) res=max(res,tr[x]); return res;
}
};
int solve(vector<pair<int,int> > &A) {
	sort(A.begin(),A.end());
	//for (pair<int,int> &X : A) printf("%d %d\n",X.first,X.second); puts("");
	mn=0; for (pair<int,int> &X : A) mn=min(mn,X.second); mn-=2;
	BIT::clear(); int res=0;
	for (pair<int,int> &X : A) {
		int tmp=BIT::query(X.second+1)+1; res=max(res,tmp);
		BIT::add(X.second,tmp);
		//printf("tmp=%d %d\n",tmp,X.second);
	}
	return res;
}
int main() {
	//freopen("1.txt","r",stdin);
	int T; read(T); while (T--) {
		read(n),read(m); A.clear(),B.clear();
		for (int i=1;i<=n;i++) {
			scanf("%s",s+1);
			for (int j=1;j<=m;j++) if (s[j]=='1') {
				if ((i+j)&1) A.push_back(MP(i+j,i-j));
				else B.push_back(MP(i+j,i-j));
			}
		}
		printf("%d\n",solve(A)+solve(B));
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