#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
int n,pos,ans[2010],vis[2010];
struct node {
	ll x,y;
	bool operator < (node t) {
		if (x!=t.x) return y<t.y; return x<t.x;
	}
	node operator - (node t) {
		return (node){x-t.x,y-t.y};
	}
	ll operator * (node t) {
		return x*t.y-y*t.x;
	}
} d[2010]; ll t; char s[2010];
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++) read(d[i].x),read(d[i].y);
	scanf("%s",s+1);
	for (int i=1;i<=n;i++)
		if (!pos||d[i]<d[pos]) pos=i;
	ans[1]=pos; vis[pos]=1; int tmp;
	for (int i=2;i<n;i++) {
		tmp=0;
		for (int j=1;j<=n;j++)
		if (!vis[j]) {
			t=(d[j]-d[pos])*(d[tmp]-d[pos]);
			if (!tmp||(s[i-1]=='L'&&t>0)||(s[i-1]=='R'&&t<0)) tmp=j;
		}
		ans[i]=pos=tmp; vis[pos]=1;
	}
	for (int i=1;i<=n;i++) if (!vis[i]) { ans[n]=i; break; }
	for (int i=1;i<=n;i++) printf("%d ",ans[i]); printf("\n");
	return 0;
}