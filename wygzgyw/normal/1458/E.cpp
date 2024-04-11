#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int INF=(1e9)+20;
int n,m;
map<int,set<int> > lose;
set<int> now;
map<int,int> seg;

vector<pair<int,int> > points;
inline bool solve(int x,int y) {
	if (lose.find(x)!=lose.end()) return lose[x].count(y);	
	auto it=prev(seg.upper_bound(x));
	return x+(it->second)==y;
}
int cmin(int &x,int y) { if (x>y) return y; return x; }
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(m);
	lose[0].emplace(0),now.emplace(0);
	int x,y;
	for (register int i=1;i<=n;++i) {
		read(x),read(y);
		lose[x].emplace(y);
		if (!x) now.emplace(y);
		else points.emplace_back(x,y);
	}
	points.emplace_back(INF,INF);
	now.emplace(INF+100000);
	sort(points.begin(),points.end());
	int lstX=0,cnt=0,at,tmp,j;
	for (register int i=0;i<points.size();) {
		x=points[i].first,y=points[i].second;
		//printf(" %d %d %d\n",x,y,cnt);
		at=lstX+1;
		while (at<x) {
			while (cnt>(*now.begin())) now.erase(now.begin());
			while (cnt==(*now.begin())) now.erase(now.begin()),++cnt;
			tmp=cmin(x,at+(*now.begin())-cnt);
			//printf("%d %d\n",at,cnt-at);
			seg[at]=cnt-at; cnt+=tmp-at,at=tmp;
		}
		while (cnt>(*now.begin())) now.erase(now.begin());
		while (cnt==(*now.begin())) now.erase(now.begin()),++cnt;
		if (y>cnt) lose[x].emplace(cnt),++cnt;
		j=i;
		while (j<points.size()&&points[j].first==x) now.emplace(points[j++].second);
		lstX=x,i=j;
	}
	while (m--) {
		read(x),read(y);
		if (solve(x,y)) puts("LOSE");
		else puts("WIN");
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