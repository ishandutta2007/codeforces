#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
int n,tot,cnt[110][27];
bool vis[10010];
string s[10010],t[110];
char ans[110];
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	printf("? 1 %d\n",n);
	fflush(stdout);
	for (int i=1;i<=n*(n+1)/2;i++) cin>>s[++tot];
	if (n==1) { printf("! "); cout<<s[1]<<endl; return 0; }
	printf("? 1 %d\n",n-1);
	fflush(stdout);
	for (int i=1;i<=n*(n-1)/2;i++) cin>>s[++tot];
	for (int i=1;i<=tot;i++) sort(s[i].begin(),s[i].end());
	sort(s+1,s+tot+1);
	for (int i=1;i<tot;i++)
		if (!vis[i]&&s[i]==s[i+1]) vis[i]=vis[i+1]=1;
	for (int i=1;i<=tot;i++)
		if (!vis[i]) t[s[i].size()]=s[i];
	//for (int i=1;i<=n;i++) cout<<t[i]<<endl;
	for (int i=1;i<=n;i++) {
		for (int j=0;j<i;j++) cnt[i][t[i][j]-'a']++;
	}
	ans[n-1]=t[1][0];
	for (int i=2;i<=n;i++) {
		for (int j=0;j<26;j++)
			if (cnt[i][j]!=cnt[i-1][j]) {
				ans[n-i]=j+'a';
				break;
			}
	}
	printf("! %s\n",ans);
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