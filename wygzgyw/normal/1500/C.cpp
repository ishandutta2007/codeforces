#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
int n,m;
bitset<1510> f[1510],all;
int a[1510][1510],b[1510][1510];
vector<int> ans;
int mk[1510],vis[1510],id,D[1510];
bool cmp(int x,int y) {
	return a[x][id]<a[y][id];
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(m);
	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) read(a[i][j]);
	int flag=1;
	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) {
		read(b[i][j]);
		if (b[i][j]!=a[i][j]) flag=0;
	}
	if (flag) { puts("0"); return 0; }
	for (int i=1;i<n;i++) for (int j=1;j<=m;j++)
		f[i][j]=(b[i][j]<=b[i+1][j]);
	while (1) {
		for (int i=1;i<=m;i++) all[i]=1;
		for (int i=1;i<n;i++) if (!mk[i]) all&=f[i];
		int pos=0;
		for (int i=1;i<=m;i++)
			if (all[i]&&!vis[i]) { pos=i; break; }
        if (!pos) break;
        ans.push_back(pos); vis[pos]=1;
        for (int i=1;i<n;i++)
        	if (b[i][pos]<b[i+1][pos]) mk[i]=1;
	}
	for (int i=1;i<=n;i++) D[i]=i;
	reverse(ans.begin(),ans.end());
	for (int i=0;i<ans.size();i++) id=ans[i],stable_sort(D+1,D+n+1,cmp);
	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++)
		if (a[D[i]][j]!=b[i][j]) { puts("-1"); return 0; }
	printf("%d\n",(int)ans.size());
	for (int x : ans) printf("%d ",x); puts("");
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