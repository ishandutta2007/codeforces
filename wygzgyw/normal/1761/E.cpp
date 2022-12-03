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
const int maxn=4010;
int T,n,deg[maxn];
char s[maxn][maxn];
int fa[maxn],E[maxn];
vector<int> vec[maxn];
int find(int x) { return fa[x]==x?x:fa[x]=find(fa[x]); }
int main() {
//	freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n);
		for (int i=1;i<=n;i++) fa[i]=i,deg[i]=E[i]=0,vec[i].clear();
		for (int i=1;i<=n;i++) {
			scanf("%s",s[i]+1);
			for (int j=i+1;j<=n;j++) if (s[i][j]=='1') fa[find(i)]=find(j),deg[i]++,deg[j]++;
		}
		for (int i=1;i<=n;i++) {
			vec[find(i)].push_back(i);
			for (int j=i+1;j<=n;j++) if (s[i][j]=='1') E[find(i)]++;
		}
		int cnt=0,flag=1;
		for (int i=1;i<=n;i++) if (find(i)==i) cnt++;
		if (cnt==1) { puts("0"); continue; }
		vector<pair<int,int> > S;
		for (int i=1;i<=n;i++) if (find(i)==i) {
			int V=(int)vec[i].size();
			if (V==1) { flag=0; continue; }
			flag&=(E[i]==V*(V-1)/2);
			S.push_back(MP(V,i));
		}
		if (!flag) {
			int mn=0;
			for (int i=1;i<=n;i++) if (find(i)==i) {
				int V=(int)vec[i].size();
				if (V==1) { mn=vec[i][0]; break; }
				if (E[i]==V*(V-1)/2) continue;
				for (int &v : vec[i]) if (!mn||deg[v]<deg[mn]) mn=v;
				break;
			}
			printf("1\n%d\n",mn); continue;
		}
		if (cnt==2) {
			sort(S.begin(),S.end());
			printf("%d\n",S[0].first);
			for (int &x : vec[S[0].second]) printf("%d ",x); puts("");
		} else {
			printf("2\n%d %d\n",vec[S[0].second].back(),vec[S[1].second].back());
		}
	}
	return 0;
}