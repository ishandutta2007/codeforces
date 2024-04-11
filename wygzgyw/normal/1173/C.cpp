#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
const int INF=(1e9);
const int maxn=(7e5)+10;
int n,a[maxn],b[maxn],ans;
int tot,vis[maxn];
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++) read(a[i]),vis[a[i]]=1;
	for (int i=1;i<=n;i++) read(b[i]);
	int flag=1;
	for (int i=1;i<=n;i++)
		if (b[i]!=i) { flag=0; break; }
	if (flag) { printf("0\n"); return 0; }
	int pos=0;
	for (int i=n;i>=1;i--) {
		if (b[i]==b[i-1]+1&&b[i-1]);
		else {
			if (b[i]==1) { pos=i; break; }
			pos=n+1; break;
		}
	}
	int mx=0,tmp;
	if (pos==n+1) pos=1;
	else {
		tot=n;
		tmp=b[n]+1;
		for (int i=1;i<pos;i++) {
			//printf("%d %d\n",tmp,vis[tmp]);
			if (!vis[tmp]) { ans=INF; break; }
			vis[tmp]=0;
			vis[b[tot-n+1]]=1;
			b[++tot]=tmp;
			ans++; tmp++;
		}
		/*for (int j=tot-n+1;j<=tot;j++)
			printf("%d ",b[j]);
		printf("\n");*/
		if (ans!=INF) {
			printf("%d\n",ans);
			return 0;
		}
	}
	for (int i=1;i<=n;i++)
		if (b[i]) mx=max(mx,i-b[i]+1);
	ans=0;
	memset(vis,0,sizeof(vis));
	for (int i=1;i<=n;i++) vis[a[i]]=1;
	tot=n;
	tmp=1;
	for (int i=1;i<=mx;i++) {
		ans++;
		vis[b[tot-n+1]]=1;
		b[++tot]=0;
	}
	/*for (int j=tot-n+1;j<=tot;j++)
		printf("%d ",b[j]);
	printf("\n");*/
	while (tmp<=n) {
		vis[tmp]=0;
		vis[b[tot-n+1]]=1;
		b[++tot]=tmp;
		ans++; tmp++;
	}
	/*for (int j=tot-n+1;j<=tot;j++)
		printf("%d ",b[j]);
	printf("\n");*/
	printf("%d\n",ans);
	return 0;
}