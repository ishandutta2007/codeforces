#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
int n,a,b,ans[110][110];
pair<int,int> d1[10010],d2[10010];
int t1,t2;
void insert(int x,int y,int z) {
	assert(ans[x][y]==0);
	ans[x][y]=z;
	printf("%d %d %d\n",z,x,y); fflush(stdout);
}
int main() {
	scanf("%d",&n);
	int p1=0,p2=0;
	for (int i=1;i<=n;i++) for (int j=1;j<=n;j++)
		if ((i+j)&1) d1[++t1]=make_pair(i,j);
		else d2[++t2]=make_pair(i,j);
	for (int i=1;i<=n*n;i++) {
		scanf("%d",&a);
		if (a!=2) {
			if (p2<t2) {
				p2++;
				insert(d2[p2].first,d2[p2].second,2);
			} else {
				p1++;
				insert(d1[p1].first,d1[p1].second,4-a);
			}
		} else {
			if (p1<t1) {
				p1++; insert(d1[p1].first,d1[p1].second,1);
			} else {
				p2++; insert(d2[p2].first,d2[p2].second,3);
			}
		}
	}
	/*for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) printf("%d",ans[i][j]); puts("");
	}*/
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