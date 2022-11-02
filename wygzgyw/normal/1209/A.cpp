#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=110;
int n,a[maxn],cnt,vis[maxn];
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++) read(a[i]);
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++)
		if (!vis[i]) {
			for (int j=i;j<=n;j++)
				if (a[j]%a[i]==0) vis[j]=1;
			cnt++;
		}
	printf("%d\n",cnt);
	return 0;
}