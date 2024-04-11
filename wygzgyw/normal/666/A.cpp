#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(1e4)+10;
int n,vis[maxn][5];
string s;
set<string> ans;
void dfs(int k,int a,string lst) {
	string now=s.substr(n-k,a);
	if (k>n-5||vis[k][a]||now==lst) return;
	vis[k][a]=1;
	ans.insert(now);
	dfs(k+2,2,now);
	dfs(k+3,3,now);
}
int main() {
	//freopen("1.txt","r",stdin);
	cin>>s; n=s.size();
	dfs(2,2,"");
	dfs(3,3,"");
	cout<<ans.size()<<endl;
	for (string t : ans) cout<<t<<"\n";
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