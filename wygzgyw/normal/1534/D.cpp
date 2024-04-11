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
int n,dep[2010],dis[2010];
vector<int> buc[2010];
int cnt[2];
vector<pair<int,int> > ans;
bool ok[2010][2010];
void query(int x) {
	printf("? %d\n",x); fflush(stdout);
	for (int i=1;i<=n;i++) {
		scanf("%d",&dep[i]);
		if (dep[i]==1&&!ok[i][x]) ans.push_back(MP(i,x)),ok[x][i]=ok[i][x]=1;
	}
}
int main() {
	scanf("%d",&n);
	printf("? 1\n"); fflush(stdout);
	for (int i=1;i<=n;i++) scanf("%d",&dep[i]);
	for (int i=2;i<=n;i++) {
		buc[dep[i]].push_back(i);
		if (dep[i]==1) ans.push_back(MP(1,i)),ok[1][i]=ok[i][1]=1;
		cnt[dep[i]&1]++;
	}
	if (cnt[0]<cnt[1]) {
		for (int i=2;i<=n;i+=2) for (int x : buc[i]) query(x);
	} else for (int i=1;i<=n;i+=2) for (int x : buc[i]) query(x);
	puts("!");
	for (int i=1;i<n;i++) printf("%d %d\n",ans[i-1].first,ans[i-1].second);
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