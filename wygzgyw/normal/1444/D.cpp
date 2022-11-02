#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
int T,n,m,s1,s2,a[1010],b[1010];
vector<int> L,R,U,D;
int x,y;
bitset<1000010> f[1010];
vector<pair<int,int> > A,B,C;
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	f[0][0]=1;
	while (T--) {
		s1=s2=0;
		read(n);
		for (int i=1;i<=n;i++) read(a[i]),s1+=a[i];
		read(m);
		for (int i=1;i<=m;i++) read(b[i]),s2+=b[i];
		if (n!=m||s1%2==1||s2%2==1) { printf("No\n"); continue; }
		s1/=2,s2/=2;
		sort(a+1,a+n+1),sort(b+1,b+m+1);
		for (int i=1;i<=n;i++) f[i]=f[i-1]|(f[i-1]<<a[i]);
		if (!f[n][s1]) { printf("No\n"); continue; }
		L.clear(),R.clear();
		for (int i=n;i>=1;i--) {
			if (s1>=a[i]&&f[i-1][s1-a[i]]) {
				s1-=a[i],L.push_back(a[i]);
			} else R.push_back(a[i]);
		}
		if ((int)L.size()<(int)R.size()) swap(L,R);
		for (int i=1;i<=m;i++) f[i]=f[i-1]|(f[i-1]<<b[i]);
		if (!f[m][s2]) { printf("No\n"); continue; }
		U.clear(),D.clear();
		for (int i=m;i>=1;i--) {
			if (s2>=b[i]&&f[i-1][s2-b[i]]) {
				s2-=b[i],U.push_back(b[i]);
			} else D.push_back(b[i]);
		}
		if ((int)D.size()>(int)U.size()) swap(U,D);
		// R<L, D<U
		A.clear(),B.clear(),C.clear();
		sort(U.begin(),U.end());
		sort(R.begin(),R.end()); reverse(R.begin(),R.end());
		for (int i=0;i<R.size();i++) A.push_back(make_pair(R[i],U[i]));
		sort(D.begin(),D.end());
		sort(L.begin(),L.end()); reverse(L.begin(),L.end());
		for (int i=0;i<D.size();i++) C.push_back(make_pair(-L[i],-D[i]));
		int pos=(int)R.size();
		for (int i=(int)D.size();i<L.size();i++) {
			B.push_back(make_pair(-L[i],U[pos]));
			pos++;
		}		
		
		printf("Yes\n");
		x=y=0;
		for (int i=0;i<A.size();i++) {
			printf("%d %d\n",x,y);
			x+=A[i].first;
			printf("%d %d\n",x,y);
			y+=A[i].second;
		}
		for (int i=0;i<B.size();i++) {
			printf("%d %d\n",x,y);
			x+=B[i].first;
			printf("%d %d\n",x,y);
			y+=B[i].second;
		}
		for (int i=0;i<C.size();i++) {
			printf("%d %d\n",x,y);
			x+=C[i].first;
			printf("%d %d\n",x,y);
			y+=C[i].second;
		}
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