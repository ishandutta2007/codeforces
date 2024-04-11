#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;

int T;
ll n,m,f[2][2][2][2];
int op;

int main() {
	read(T);
	while (T--) {
		read(n),read(m);
		op=0;
		memset(f[op],0,sizeof(f[op]));
		f[op][0][0][0]=1;
		for (int i=0;i<=61;i++) {
			memset(f[op^1],0,sizeof(f[op^1]));
			for (int jw=0;jw<=1;jw++) for (int k=0;k<=1;k++) for (int v=0;v<=1;v++) if (f[op][jw][k][v]) {
				for (int x=0;x<=1;x++) {
					int y=(x+jw+(n>>i&1));
					int k2=k,v2=v;
					if (y&1) k2^=1;
					if (x) k2^=1;
					if ((m>>i&1)&&!x) v2=1;
					if (!(m>>i&1)&&x) v2=0;
					f[op^1][y>=2][k2][v2]+=f[op][jw][k][v];
				}
			}
			op^=1;
		}
		printf("%lld\n",f[op][0][1][1]);
	}
	return 0;
}