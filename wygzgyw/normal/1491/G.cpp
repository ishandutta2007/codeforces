#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(2e5)+10;
int n,p[maxn];
int vis[maxn];
vector<pair<int,int> > ans;
void solve(int x,int y) {
	swap(p[x],p[y]);
	ans.emplace_back(x,y);
}
void change(int x,int y) {
	while (p[x]!=y) solve(x,p[x]);
	while (p[y]!=x) solve(y,p[y]);
	solve(x,y);
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++) read(p[i]);
	int pos=-1;
	for (int i=1;i<=n;i++) if (!vis[i]) {
		int x=i;
		for (;!vis[x];x=p[x]) vis[x]=1;
		if (i!=p[i]) {
			if (pos==-1) pos=i;
			else solve(pos,i),change(pos,i),pos=-1;
		}
	}
	
	if (pos!=-1) {
		int x;
		if (p[p[pos]]==pos) {
			x=1;
			while (x==pos||x==p[pos]) x++;
			solve(x,pos);
		} else {
			x=p[pos];
			solve(pos,x);
			solve(x,p[pos]);
		}
		change(pos,x);
		
	}
	printf("%d\n",(int)ans.size());
	for (pair<int,int> A : ans) printf("%d %d\n",A.first,A.second);
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