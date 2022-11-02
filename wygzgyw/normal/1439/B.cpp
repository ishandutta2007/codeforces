#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(1e5)+10;
int T,n,m,k;
bool flag;
vector<int> ans;
unordered_set<int> g[maxn];
priority_queue<pair<int,int> > q;
unordered_set<int>::iterator it,it2;
int main() {
	//freopen("1.txt","r",stdin);
	int x,y;
	read(T);
	while (T--) {
		read(n),read(m),read(k);
		ans.clear();
		for (int i=1;i<=n;i++) g[i].clear();
		for (int i=1;i<=m;i++) {
			read(x),read(y);
			g[x].insert(y),g[y].insert(x);
		}
		if (k==1) { printf("2\n1\n"); continue; }
		q=priority_queue<pair<int,int> >();
		for (int i=1;i<=n;i++) q.push(make_pair(-(int)g[i].size(),i));
		flag=0;
		while (!q.empty()) {
			int u=q.top().second; q.pop();
			if (g[u].empty()) continue;
			if ((int)g[u].size()>=k) { flag=1; break; }
			if ((int)g[u].size()==k-1&&(ll)k*(k-1)/2<=m) {
				bool f=1;
				for (it=g[u].begin();f&&it!=g[u].end();it++)
				for (it2=it,it2++;f&&it2!=g[u].end();it2++) {
					f&=g[*it].find(*it2)!=g[*it].end();
				}
				if (f) {
					for (it=g[u].begin();it!=g[u].end();it++) ans.push_back(*it);
					ans.push_back(u);
					break;
				}
			}
			for (it=g[u].begin();it!=g[u].end();it++) g[*it].erase(u),q.push(make_pair(-(int)g[*it].size(),*it));
			g[u].clear();
		}
		if (ans.size()) {
			printf("2\n");
			for (int i=0;i<ans.size();i++) printf("%d ",ans[i]); printf("\n");
		} else if (flag) {
			for (int i=1;i<=n;i++) if ((int)g[i].size()) ans.push_back(i);
			printf("1 %d\n",(int)ans.size());
			for (int i=0;i<ans.size();i++) printf("%d ",ans[i]); printf("\n");
		} else printf("-1\n");
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