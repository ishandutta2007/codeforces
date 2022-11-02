#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int INF=1e9;
const int maxn=(1e6)+10;
int n,m;
int a[1010][1010];
int query(int x,int y) {
	printf("? %d %d\n",x,y); fflush(stdout);
	scanf("%d",&x); return x;
	//return a[x][y];
}
int X[maxn],Y[maxn],tot;
vector<int> solve(vector<int> r,vector<int> c) {
	vector<int> res; int L,R;
	//for (int x : r) printf("%d ",x); printf(","); for (int x : c) printf("%d ",x); puts("");
	if ((int)r.size()>=(int)c.size()) {
		if ((int)r.size()==1) {
			L=0,R=(int)c.size()-1;
			int t,pos,mn=INF;
			for (int i=L;i<=R;i++) {
				t=query(r[0],c[i]);
				if (t<mn) mn=t,pos=i;
			}
			return {pos,mn};
		}
		vector<int> u,A;
		for (int i=0;i<(int)r.size();i+=2) u.push_back(r[i]);
		A=solve(u,c); int MN=A.back();
		for (int i=0;i<r.size();i++) if (i&1) {
			L=A[i/2];
			if (i+1<(int)r.size()) R=A[(i+1)/2]; else R=(int)c.size()-1;
			int mn=INF,pos;
			for (int j=L;j<=R;j++) {
				int t=query(r[i],c[j]);
				if (t<mn) mn=t,pos=j;
			}
			MN=min(MN,mn);
			res.push_back(pos);
		} else res.push_back(A[i/2]);
		res.push_back(MN);
		return res;
	} else {
		tot=0;
		for (int i=0;i<c.size();i++) {
			while (tot) {
			//	printf("HIHI %d\n",c[i]);
				if (query(r[X[tot]],c[Y[tot]])<=query(r[X[tot]],c[i])) {
					if (X[tot]+1<(int)r.size()) {
						tot++; X[tot]=X[tot-1]+1,Y[tot]=i;
					}
					break;
				} else tot--;
			}
			if (!tot) tot++,X[tot]=0,Y[tot]=i;
			//printf("%d:",c[i]);
			//for (int j=1;j<=tot;j++) printf("%d ",Y[j]); puts("");
		}
		vector<int> u; for (int i=1;i<=tot;i++) u.push_back(c[Y[i]]);//,printf("HI %d\n",Y[i]);
		vector<int> A=solve(r,u);
		int pos=0;
		for (int i=0;i<(int)A.size()-1;i++) {
			while (c[pos]<u[A[i]]) pos++;
			A[i]=pos;
		}
		return A;
	}
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(m);
//	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) read(a[i][j]);
	vector<int> r,c;
	for (int i=1;i<=n;i++) r.push_back(i);
	for (int i=1;i<=m;i++) c.push_back(i);
	vector<int> ans=solve(r,c);
	printf("! %d\n",ans.back());
	fflush(stdout);
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