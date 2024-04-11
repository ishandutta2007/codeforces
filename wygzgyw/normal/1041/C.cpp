#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(2e5)+10;
const int INF=2e9;
int n,m,tot,ans[maxn],x;
pair<int,int> d[maxn];
set<pair<int,int> > s;
set<pair<int,int> >::iterator it;
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(m); read(x);
	for (int i=1;i<=n;i++) read(d[i].first),d[i].second=i;
	sort(d+1,d+(n+1));
	s.insert(make_pair(d[1].first,1));
	tot=1; ans[d[1].second]=1;
	for (int i=2;i<=n;i++) {
		it=s.begin();
		int tmp=d[i].first-(x+1);
		if ((*it).first>tmp) {
			ans[d[i].second]=++tot;
			s.insert(make_pair(d[i].first,tot));
			continue;
		}
		it=s.lower_bound(make_pair(tmp+1,-INF)); it--;
		ans[d[i].second]=(*it).second;
		s.erase(it);
		s.insert(make_pair(d[i].first,(*it).second));
	}
	printf("%d\n",tot);
	for (int i=1;i<=n;i++) printf("%d ",ans[i]);
	printf("\n");
	return 0;
}