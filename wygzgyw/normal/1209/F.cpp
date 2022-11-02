#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const ll mod=(1e9)+7;
const int maxn=(2e6)+5;
int n,m,tot,d[maxn],sz,ans[maxn];
bool vis[maxn];
vector<int> g[maxn][10];
void add(int x,int y,int z) {
	g[x][z].push_back(y);
}
queue<vector<int> > q;
vector<int> A,B;
void solve(int x,int y) {
	if (sz==1) { add(x,y,d[1]); return; }
	tot++,add(x,tot,d[1]);
	for (int j=2;j<sz;j++)
		tot++,add(tot-1,tot,d[j]);
	add(tot,y,d[sz]);
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(m);
	int x,y,z; tot=n;
	for (int i=1;i<=m;i++) {
		read(x); read(y); z=i; sz=0;
		while (z) {
			d[++sz]=z%10; z/=10;
		}
		reverse(d+1,d+sz+1);
		solve(x,y);
		swap(x,y);
		solve(x,y);
	}
	A.push_back(1);
	q.push(A); vis[1]=1;
	while (!q.empty()) {
		A=q.front(); q.pop();
		for (int i=0;i<10;i++) {
			B.clear();
			for (int j=0,u;j<A.size();j++) {
				u=A[j];
				for (int k=0,v;k<g[u][i].size();k++) {
					v=g[u][i][k];
					if (vis[v]) continue; vis[v]=1;
					ans[v]=((ll)ans[u]*10+i)%mod;
					B.push_back(v);
				}
			}
			if (B.size()>0) q.push(B);
		}
	}
	for (int i=2;i<=n;i++) printf("%d\n",ans[i]);
	return 0;
}