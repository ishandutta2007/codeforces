#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int INF=(1e6);
int n,x[1010],y[1010],A,B,cnt;
vector<int> a[2][2],r;
void find(vector<int> s1,vector<int> s2) {
	printf("%d\n",s1.size()+s2.size());
	for (int i=0;i<s1.size();i++) printf("%d ",s1[i]);
	for (int i=0;i<s2.size();i++) printf("%d ",s2[i]);
	printf("\n");
	exit(0);
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++) {
		read(x[i]),read(y[i]);
		x[i]+=INF,y[i]+=INF;
	}
	while (1) {
		for (int i=0;i<=1;i++)
		for (int j=0;j<=1;j++) a[i][j].clear();
		for (int i=1;i<=n;i++)
			a[x[i]%2][y[i]%2].push_back(i);
		A=B=cnt=0;
		for (int i=0;i<=1;i++)
		for (int j=0;j<=1;j++) {
			if (a[i][j].size()) A=i,B=j,cnt++;
		}
		if (cnt==1) {
			for (int i=1;i<=n;i++)
				x[i]=(x[i]-A)/2,y[i]=(y[i]-B)/2;
			continue;
		}
		if (a[0][0].size()+a[1][1].size()==n) find(a[0][0],r);
		if (a[0][1].size()+a[1][0].size()==n) find(a[0][1],r);
		find(a[0][0],a[1][1]);
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