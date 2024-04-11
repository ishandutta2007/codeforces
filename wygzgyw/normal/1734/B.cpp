#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
int T,n;
int f[510][510];
int suf[510];

int main() {
	read(T);
	while (T--) {
		read(n);
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=i;j++) printf("%d ",i==j||j==1); puts("");
		}
		continue;
		memset(f,0,sizeof(f));
		memset(suf,0,sizeof(suf));
		for (int i=1;i<=n;i++) {
			int mn=1e9,mx=0;
			for (int j=1;j<=i;j++) {
				mx=max(mx,f[i][j]);
				mn=min(mn,f[i][j]);
			}
			assert(abs(mn-mx)<=1);
			for (int j=1;j<=i;j++) {
				if (f[i][j]==mn) {
					f[i][j]++,printf("1 ");
					for (int k=i+1;k<=n;k++) for (int v=j;v<=j+k-i;v++) f[k][v]++;
				}
				else printf("0 ");
			} puts("");
		}
	}
	return 0;
}