#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(5e5)+10;
int n,q,fa[maxn];
int op,x,y;
double f[maxn][51],ans,lst;
int main() {
	//freopen("1.txt","r",stdin);
	n=1; for (int i=0;i<=50;i++) f[1][i]=1;
	read(q);
	while (q--) {
		read(op),read(x);
		if (op==1) {
			n++; fa[n]=x;
			lst=f[x][0];
			for (int i=0;i<=50;i++) f[n][i]=1;
			f[x][0]=f[x][0]*0.5;
			for (int i=1;i<=50;i++) {
				y=x;
				x=fa[x];
				if (!x) break;
				f[x][i]/=(0.5+0.5*lst);
				lst=f[x][i]*(0.5+0.5*lst);
				f[x][i]*=(0.5+0.5*f[y][i-1]);
			}
		} else {
			ans=0;
			for (int i=1;i<=50;i++) ans+=(f[x][i]-f[x][i-1])*i;
			printf("%.10lf\n",ans);
		}
	}
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