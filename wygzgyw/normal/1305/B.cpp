#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=1010;
int n,m,tot,c1,c2,N,len;
char s[maxn],t[maxn];
vector<int> ans[maxn];
int L[maxn],R[maxn];
bool vis[maxn];
int main() {
	//freopen("1.txt","r",stdin);
	scanf("%s",s+1);
	n=strlen(s+1);
	while (1) {
		for (int i=1;i<=n;i++) L[i]=n+1,R[i]=0,vis[i]=0;
		c1=c2=0;
		for (int i=1;i<=n;i++) {
			if (s[i]=='(') L[++c1]=i;
		}
		for (int i=n;i>=1;i--) {
			if (s[i]==')') R[++c2]=i;
		}
		len=0;
		for (int i=min(c1,c2);i>=1;i--)
			if (L[i]<R[i]) { len=i; break; }
		if (!len) break;
		c1=c2=0;
		tot++;
		for (int i=1;i<=n;i++)
			if (s[i]=='(') {
				c1++;
				ans[tot].push_back(i);
				vis[i]=1;
				if (c1==len) break;
			}
		int lst=0;
		for (int i=n;i>=1;i--)
			if (s[i]==')') {
				c2++;
				lst=i;
				vis[i]=1;
				if (c2==len) break;
			}
		for (int i=lst;i<=n;i++)
			if (s[i]==')') ans[tot].push_back(i);
		N=0;
		for (int i=1;i<=n;i++)
			if (!vis[i]) t[++N]=s[i];
		n=N;
		for (int i=1;i<=n;i++) s[i]=t[i];
	}
	printf("%d\n",tot);
	for (int i=1;i<=tot;i++) {
		printf("%d\n",ans[i].size());
		for (int j=0;j<ans[i].size();j++) printf("%d ",ans[i][j]);
		printf("\n");
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