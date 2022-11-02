// wygzgyw
#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
template <typename T> void write(T t) {
	if (t<0) { putchar('-'); write(-t); return; }
	if (t>9) write(t/10);
	putchar('0'+t%10);
}
template <typename T> void writeln(T t) { write(t); puts(""); }
#define MP make_pair
const int maxn=(6e5)+10;
int n;
char s[2][maxn],t[2][maxn];
vector<int> ans[2],V;
vector<pair<int,int> > g[maxn];
bool vis[maxn],v2[maxn];
void dfs(int u) {
	V.push_back(u);
	if (vis[u]) return;
	vis[u]=1;
	//printf("u=%d\n",u);
	for (auto [v,w] : g[u]) if (!v2[w]) {
		v2[w]=1;
		dfs(v);
		V.push_back(u);
	}
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++) {
		int x,y; read(x),read(y);
		g[x].push_back(MP(y,i)),g[y].push_back(MP(x,i));
	}
	ans[0].resize(n+1),ans[1].resize(n+1);
	for (int i=1;i<=n;i++) s[0][i]='U',t[0][i]='U',s[1][i]='D',t[1][i]='D';
	int cnt=0;
	for (int i=1;i<=n*2;i++) if (!vis[i]) {
		V.clear();
		dfs(i);
		//for (int &x : V) printf("%d ",x); puts("");
		if ((int)V.size()==3) { puts("-1"); return 0; }
		int len=(int)V.size()/2;
		if (!len) continue;
		V.pop_back();
		int l=0,r=(int)V.size()-1;
		for (int j=cnt+1;j<=cnt+len;j++) {
			ans[0][j]=V[l],l++;
			ans[1][j]=V[r],r--;
		}
		for (int j=cnt+1;j<cnt+len;j+=2) {
			s[0][j]=s[1][j]='L',s[0][j+1]=s[1][j+1]='R';
		}
		for (int j=cnt+2;j<cnt+len;j+=2) {
			t[0][j]=t[1][j]='L',t[0][j+1]=t[1][j+1]='R';
		}
		cnt+=len;
	}
	printf("%d %d\n",2,n);
	
	puts("");
	for (int i=0;i<2;i++) {
		for (int j=1;j<=n;j++) printf("%d ",ans[i][j]); puts("");
	}
	puts("");
	cout<<s[0]+1<<endl;
	cout<<s[1]+1<<endl;
	
	puts("");
	cout<<t[0]+1<<endl;
	cout<<t[1]+1<<endl;
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