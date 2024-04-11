#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(3e5)+10;
int n,a[maxn],t,pos,tot,ch[maxn*31][2];
vector<int> g[maxn*31];
int x;
ll dp[32][2],ans;
void dfs(int x,int dep) {
	int ls=ch[x][0],rs=ch[x][1];
	if (ls) dfs(ls,dep+1);
	if (rs) dfs(rs,dep+1);
	if (!ls||!rs) return;
	ll res=0;
	int pos=0;
	for (int i=0;i<g[ls].size();i++) {
		while (pos<(int)g[rs].size()&&g[rs][pos]<g[ls][i]) pos++;
		res+=pos;
	}
	dp[dep][0]+=res;
	dp[dep][1]+=(ll)((int)g[ls].size())*(int)g[rs].size()-res;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	tot=1;
	for (int i=1;i<=n;i++) {
		read(a[i]);
		pos=1;
		for (int j=30;j>=0;j--) {
			t=(a[i]>>j&1);
			if (!ch[pos][t]) ch[pos][t]=++tot;
			pos=ch[pos][t];
			g[pos].push_back(i);
		}
	}
	dfs(1,0);
	for (int i=30;i>=0;i--) {
		ans+=min(dp[i][0],dp[i][1]);
		if (dp[i][1]<dp[i][0]) x+=(1<<(30-i));
	}
	printf("%lld %d\n",ans,x);
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