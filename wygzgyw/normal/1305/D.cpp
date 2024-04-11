#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=1010;
int n,deg[maxn],cnt;
vector<int> g[maxn];
queue<int> q;
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	int x,y,z;
	for (int i=1;i<n;i++) {
		read(x); read(y);
		deg[x]++; deg[y]++;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for (int i=1;i<=n;i++)
		if (deg[i]==1) q.push(i);
	while (q.size()>1) {
		x=q.front(); q.pop();
		y=q.front(); q.pop();
		deg[x]--; deg[y]--;
		printf("? %d %d\n",x,y);
		fflush(stdout);
		read(z);
		if (z==x||z==y) { printf("! %d\n",z); fflush(stdout); return 0; }
		for (int i=0;i<g[x].size();i++) {
			z=g[x][i];
			deg[z]--;
			if (deg[z]==1) q.push(z);
		}
		for (int i=0;i<g[y].size();i++) {
			z=g[y][i];
			deg[z]--;
			if (deg[z]==1) q.push(z);
		}
	}
	x=q.front(); q.pop();
	printf("! %d\n",x); fflush(stdout);
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