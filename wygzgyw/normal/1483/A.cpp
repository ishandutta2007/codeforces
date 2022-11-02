#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(2e5)+10;
int T,n,m,len[maxn];
vector<int> g[maxn];
int x,ans[maxn];
bool cmp(int x,int y) { return len[x]<len[y]; }
int id[maxn],cnt[maxn];
int main() {
//	freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n),read(m);
		for (int i=1;i<=m;i++) {
			read(len[i]); g[i].clear();
			for (int j=0;j<len[i];j++) read(x),g[i].push_back(x);
			id[i]=i;
		}
		sort(id+1,id+m+1,cmp);
		for (int i=1;i<=n;i++) cnt[i]=0;
		for (int I=1;I<=m;I++) {
			int i=id[I],pos=0;
			for (int j=0;j<len[i];j++)
				if (pos==0||cnt[pos]>cnt[g[i][j]]) pos=g[i][j];
			cnt[pos]++; ans[i]=pos;
		}
		int flag=1;
		for (int i=1;i<=n;i++) if (cnt[i]>(m+1)/2) { flag=0; break; }
		if (!flag) puts("NO");
		else {
			puts("YES");
			for (int i=1;i<=m;i++) printf("%d ",ans[i]);
			puts("");
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