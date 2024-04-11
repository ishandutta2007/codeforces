#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(1e5)+10;
int T,n;
vector<pair<int,int> > ans;
int a[maxn],lst;
queue<int> q;
int now;
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++) read(a[i]);
	for (int i=1;i<=n;i++) if (a[i]) {
		if (a[i]==1&&!q.empty()) {
			ans.push_back(make_pair(q.front(),i));
			q.pop();
		} else {
			if (lst==3) ans.push_back(make_pair(now,i));
			ans.push_back(make_pair(++now,i));
			if (a[i]==2) q.push(now);
			lst=a[i];
		}
	}
	if (lst==3||!q.empty()) { puts("-1"); return 0; }
	printf("%d\n",(int)ans.size());
	for (int i=0;i<ans.size();i++) printf("%d %d\n",ans[i].first,ans[i].second);
	return 0;
}
/*
  REMEMBER:
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Array size? Integer overflow? Time complexity? Memory usage? Precision error?
*/