#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=1010;
int T,n,a[maxn],vis[maxn],mex,cnt;
vector<int> ans;
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n);
		ans.clear();
		for (int i=0;i<n;i++) read(a[i]);
		int pos; cnt=0;
		memset(vis,0,sizeof(vis));
		while (1) {
			pos=-1;
			for (int i=0;i<n;i++) if (a[i]!=i) { pos=i; break; }
			if (pos==-1) break;
			cnt++;
			for (int i=0;i<n;i++) vis[a[i]]=cnt;
			for (int i=0;i<=n;i++) if (vis[i]!=cnt) { mex=i; break; }
			if (mex==n) ans.push_back(pos),a[pos]=n;
			else ans.push_back(mex),a[mex]=mex;
			//for (int i=0;i<n;i++) printf("%d ",a[i]); printf("\n");
		}
		printf("%d\n",ans.size());
		for (int i=0;i<ans.size();i++) printf("%d ",ans[i]+1);
		printf("\n");
	}
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Interger overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/