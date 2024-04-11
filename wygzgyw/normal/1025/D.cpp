#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar();
	while ('0'>ch||ch>'9') ch=getchar();
	do { (t*=10)+=ch-'0';ch=getchar(); }while ('0'<=ch&&ch<='9');
}
int n,x[710],a[710][710],b[710][710],con[710][710];
int gcd(int X,int Y) {
	if (!Y) return X;
	return gcd(Y,X%Y);
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++) {
		read(x[i]); a[i][i]=b[i][i]=1;
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (gcd(x[i],x[j])>1) con[i][j]=1;
	for (int len=1;len<=n;len++) {
		for (int l=1;l+len-1<=n;l++) {
			int r=l+len-1;
			for (int k=l;k<=r;k++)
			if (a[l][k]&&b[k][r]) {
				if (l==1&&r==n) {
					printf("Yes\n"); return 0;
				}
				if (con[l-1][k]) b[l-1][r]=1;
				if (con[r+1][k]) a[l][r+1]=1;
			}
		}
	}
	printf("No\n");
	return 0;
}