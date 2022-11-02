#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(3e5)+10;
int n,q,a[maxn];
int fst[maxn][20];
int to[maxn][20],tmp;
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(q); int lst,x,y,flag;
	for (int i=1;i<=n;i++) read(a[i]);
	for (int j=0;j<=19;j++) {
		lst=0;
		for (int i=n;i>=1;i--) {
			fst[i][j]=lst;
			if (a[i]&(1<<j)) lst=i;
		}
	}
	for (int j=0;j<=19;j++) {
		for (int i=n;i>=1;i--) {
			if (a[i]&(1<<j)) to[i][j]=i;
			else { tmp=(1e9);
				for (int k=0;k<=19;k++)
					if ((a[i]&(1<<k))&&fst[i][k])
						tmp=min(tmp,to[fst[i][k]][j]);
				to[i][j]=tmp;
			}
		}
	}
	while (q--) {
		read(x); read(y); flag=0;
		for (int i=0;i<=19;i++)
			if ((a[y]&(1<<i))&&to[x][i]<=y) { flag=1; break; }
		if (flag) printf("Shi\n");
		else printf("Fou\n");
	}
	return 0;
}