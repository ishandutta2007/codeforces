#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=2010;
int n,a[maxn],s;
vector<pair<int,int> > B,ans;
struct node {
	ll x,y;
	friend node operator + (node t1,node t2) {
		return (node){t1.x+t2.x,t1.y+t2.y};
	}
	friend node operator - (node t1,node t2) {
		return (node){t1.x-t2.x,t1.y-t2.y};
	}
	friend ll operator * (node t1,node t2) {
		return t1.x*t2.y-t1.y*t2.x;
	}
	int sig() {
		return (y<0)||(y==0&&x<0);
	}
} p[maxn];
vector<int> vec;
int vis[maxn],cnt,bel[maxn];
vector<int> cyc[maxn];
bool cmp(int x,int y) {
	node t1=(p[x]-p[s]),t2=(p[y]-p[s]);
	if (t1.sig()!=t2.sig()) return t1.sig()<t2.sig();
	return (t1*t2)>0;
}
void solve(int x,int y) {
	ans.push_back(make_pair(x,y));
	swap(a[x],a[y]);
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n); int flag=0,x,y;
	for (int i=1;i<=n;i++) {
		read(p[i].x),read(p[i].y),read(a[i]);
		if (a[i]!=i) flag=1;
	}
	if (!flag) { puts("0"); return 0; }
	for (int i=1;i<=n;i++) if (a[i]!=i&&!vis[i]) {
		s=x=i; cnt++;
		while (1) {
			x=a[x]; vis[x]=1;
			bel[x]=cnt; cyc[cnt].push_back(x);
			if (x==i) break;
		}
	}
	for (int i=1;i<=n;i++) if (i!=s&&a[i]!=i) vec.push_back(i);
	sort(vec.begin(),vec.end(),cmp);
	vec.push_back(vec[0]);
	for (int i=0;i<vec.size()-1;i++) {
		if (((p[vec[i]]-p[s])*(p[vec[i+1]]-p[s]))>0) B.emplace_back(vec[i],vec[i+1]);
	}
	for (pair<int,int> tmp : B) {
		x=tmp.first,y=tmp.second;
		x=bel[x],y=bel[y];
		if (x!=y) {
			solve(tmp.first,tmp.second);
			for (int a : cyc[x]) cyc[y].push_back(a),bel[a]=y;
			cyc[x].clear();
		}
	}
	while (a[s]!=s) solve(a[s],s);
	printf("%d\n",(int)ans.size());
	for (pair<int,int> tmp : ans) printf("%d %d\n",tmp.first,tmp.second);
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