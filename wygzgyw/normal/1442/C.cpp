#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(2e5)+10;
const int mod=998244353;
int n,m;
vector<int> g[maxn][2];
struct node {
	int k,dis,x;
	friend bool operator < (node t1,node t2) {
		if (t1.k==t2.k) return t1.dis>t2.dis;
		if (t1.k>19||t2.k>19) return t1.k>t2.k;
		return ((1<<t1.k)+t1.dis)>((1<<t2.k)+t2.dis);
	}
};
priority_queue<node> q;
bool vis[maxn][21];
int ksm(int x,int y) {
	int res=1;
	while (y) {
		if (y&1) res=(ll)res*x%mod;
		x=(ll)x*x%mod; y>>=1;
	} return res;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(m);
	int x,y,kk,k,dis; bool flag;
	while (m--) {
		read(x),read(y);
		g[x][0].push_back(y);
		g[y][1].push_back(x);
	}
	q.push((node){0,0,1});
	while (!q.empty()) {
		node A=q.top(); q.pop();
		k=A.k,dis=A.dis,x=A.x;
		flag=(k&1);
		if (k<=19) kk=k;
		else if (flag) kk=19;
		else kk=20;
		if (x==n) {
			printf("%d\n",(ksm(2,k)+dis-1)%mod);
			return 0;
		}
		if (vis[x][kk]) continue;
		vis[x][kk]=1;
		for (int i=0;i<g[x][flag].size();i++) {
			y=g[x][flag][i];
			q.push((node){k,dis+1,y});
		}
		q.push((node){k+1,dis,x});
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