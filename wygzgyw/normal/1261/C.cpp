#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(1e6)+10;
int n,m;
char s[maxn];
vector<int> d[maxn],s1[maxn],s2[maxn],ans[maxn];
int cnt(int x1,int y1,int x2,int y2) {
	return s1[x2][y2]-s1[x1-1][y2]-s1[x2][y1-1]+s1[x1-1][y1-1];
}
bool solve(int t,bool flag) {
	for (int i=0;i<=n+1;i++)
	for (int j=0;j<=m+1;j++) s2[i][j]=0;
	for (int i=t;i+t-1<=n;i++)
	for (int j=t;j+t-1<=m;j++) {
		//if (t==2&&flag) printf("mid=%d %d %d %d\n",t,i,j,cnt(i-t+1,j-t+1,i+t-1,j+t-1));
		if (cnt(i-t+1,j-t+1,i+t-1,j+t-1)==(t*2-1)*(t*2-1)) {
			if (flag) ans[i][j]=1;
			s2[i-t+1][j-t+1]++;
			s2[i-t+1][j+t]--;
			s2[i+t][j-t+1]--;
			s2[i+t][j+t]++;
		}
	}
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++) {
		s2[i][j]+=s2[i][j-1]+s2[i-1][j]-s2[i-1][j-1];
		
		if (s2[i][j]<d[i][j]) return 0;
	}
	return 1;
}
int main() {
	//freopen("1.txt","r",stdin);
	//printf("%d\n",sizeof(d)/1024/1024);
	read(n); read(m);
	for (int i=0;i<=n+1;i++) {
		d[i].resize(m+2);
		s1[i].resize(m+2);
		s2[i].resize(m+2);
		ans[i].resize(m+2);
	}
	for (int i=1;i<=n;i++) {
		scanf("%s",s+1);
		for (int j=1;j<=m;j++)
			if (s[j]=='X') d[i][j]=1;
	}
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
		s1[i][j]=d[i][j]+s1[i][j-1]+s1[i-1][j]-s1[i-1][j-1];
	int l,r,mid,res;
	l=1,r=min(n,m);
	while (l<=r) {
		mid=(l+r)/2;
		if (solve(mid,0)) l=mid+1,res=mid;
		else r=mid-1;
	}
	printf("%d\n",res-1);
	solve(res,1);
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++)
			if (ans[i][j]) printf("X");
			else printf(".");
		printf("\n");
	}
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