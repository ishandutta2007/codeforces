#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
int a[7]={0,4,8,15,16,23,42};
int b[1000][7],c[7],d[7],vis[7];
int main() {
	//freopen("1.txt","r",stdin);
	for (int i=1;i<=6;i++)
	for (int j=i+1;j<=6;j++)
		b[a[i]*a[j]][i]=b[a[i]*a[j]][j]=1;
	for (int i=1;i<=4;i++) {
		printf("? %d %d\n",i,i+1);
		fflush(stdout);
		read(c[i]);
	}
	for (int i=1;i<4;i++) {
		for (int j=1;j<=6;j++)
			if (b[c[i]][j]&&b[c[i+1]][j]) {
				d[i+1]=a[j]; break;
			}
	}
	d[1]=c[1]/d[2]; d[5]=c[4]/d[4];
	for (int i=1;i<=6;i++)
	for (int j=1;j<=6;j++) if (d[i]==a[j]) vis[j]=1;
	for (int i=1;i<=6;i++) if (!vis[i]) { d[6]=a[i]; break; }
	printf("! ");
	for (int i=1;i<=6;i++) printf("%d ",d[i]); printf("\n");
	return 0;
}