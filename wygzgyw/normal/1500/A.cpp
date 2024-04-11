#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(5e6)+10;
int n,a[maxn],fd[maxn],ban[maxn];
pair<int,int> ok[maxn];
vector<int> g[maxn/2];
int main() {
	//printf("%d\n",sizeof(g)/1024/1024);
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++) read(a[i]),g[a[i]].push_back(i);
	int pos=0;
	for (int i=1;i<=2500000;i++) if ((int)g[i].size()>=2) {
		if ((int)g[i].size()>=4) {
			printf("YES\n%d %d %d %d\n",g[i][0],g[i][1],g[i][2],g[i][3]);
			exit(0);
		}
		if (!pos) pos=i;
		else {
			printf("YES\n%d %d %d %d\n",g[i][0],g[pos][0],g[i][1],g[pos][1]);
			exit(0);
		}
	}
	if (pos) {
		for (int i=1;i<=n;i++) if (a[i]!=pos&&pos+pos-a[i]>=1&&pos+pos-a[i]<=2500000) {
			if ((int)g[pos+pos-a[i]].size()>0) {
				printf("YES\n%d %d %d %d\n",i,g[pos+pos-a[i]][0],g[pos][0],g[pos][1]);
				exit(0);
			}
		}
	}
	for (int i=1;i<=n;i++) fd[a[i]]=i;
	sort(a+1,a+n+1); n=unique(a+1,a+n+1)-a-1;
	int mx=0;
	for (int i=1;;i++)
		if ((ll)i*(i-1)/2>=10000000) { mx=i; break; }
	n=min(n,mx);
	for (int i=1;i<=n;i++)
	for (int j=i+1;j<=n;j++) {
		if (ok[a[i]+a[j]].first!=0) {
			printf("YES\n%d %d %d %d\n",fd[a[i]],fd[a[j]],fd[a[ok[a[i]+a[j]].first]],fd[a[ok[a[i]+a[j]].second]]); exit(0);
		} else ok[a[i]+a[j]]=make_pair(i,j);
	}
	puts("NO");
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