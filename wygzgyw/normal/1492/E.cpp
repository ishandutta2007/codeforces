#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=250010;
int n,m;
vector<int> a[maxn];
void check(vector<int> ans,bool flag) {
	for (int i=0;i<n;i++) {
		int cnt=0;
		for (int j=0;j<m;j++) {
			if (a[i][j]!=ans[j]) cnt++;
			if (cnt>3) return;
		}
		if (cnt>2) {
			if (flag) return;
			for (int j=0;j<m;j++) if (a[i][j]!=ans[j]) {
				vector<int> tmp=ans;
				tmp[j]=a[i][j];
				check(tmp,1);
			}
			return;
		}
	}
	puts("Yes");
	for (int i=0;i<m;i++) printf("%d ",ans[i]); puts("");
	exit(0);
}
int main() {
//	freopen("1.txt","r",stdin);
	read(n),read(m); int x;
	for (int i=0;i<n;i++)
	for (int j=0;j<m;j++) read(x),a[i].push_back(x);
	check(a[0],0); int t1,t2;
	for (int i=0;i<n;i++) {
		vector<int> dif;
		for (int j=0;j<m;j++) if (a[i][j]!=a[0][j]) dif.push_back(j);
		if ((int)dif.size()>=5) { puts("No"); return 0; }
		if ((int)dif.size()<=2) continue;
		for (int x : dif) for (int y : dif) {
			vector<int> tmp=a[0];
			tmp[x]=a[i][x],tmp[y]=a[i][y];
			check(tmp,0);
		}
		break;
	}
	puts("No");
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