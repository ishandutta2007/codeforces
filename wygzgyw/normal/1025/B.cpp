#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template <typename T> void read(T &t) {
	t=0; char ch=getchar();
	while ('0'>ch||ch>'9') ch=getchar();
	do { (t*=10)+=ch-'0';ch=getchar(); }while ('0'<=ch&&ch<='9');
}
int n,tot,x[1000010],y[1000010],z[1000010];
int main() {
//	freopen("1.txt","r",stdin);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		read(x[i]),read(y[i]);
	int a=x[1],b=y[1];
	for (int i=2;i*i<=max(a,b);i++)
		if (a%i==0||b%i==0) {
			while (a%i==0) a/=i;
			while (b%i==0) b/=i;
			z[++tot]=i;
		}
	if (a!=1) z[++tot]=a;
	if (a!=b&&b!=1) z[++tot]=b;
	for (int i=2;i<=n;i++)
	for (int j=1;j<=tot;j++)
		if (z[j]&&x[i]%z[j]!=0&&y[i]%z[j]!=0) z[j]=0;
	for (int i=1;i<=tot;i++)
		if (z[i]) { printf("%d\n",z[i]); return 0; }
	printf("-1\n");
	return 0;
}