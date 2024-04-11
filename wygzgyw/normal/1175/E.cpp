#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(5e5)+10;
int n,m,fa[maxn][20];
pair<int,int> d[maxn];
int mx,x,y,ans;
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(m);
	for (int i=1;i<=n;i++) {
		read(d[i].first),read(d[i].second);
		d[i].first++; d[i].second++;
	}
	sort(d+1,d+n+1);
	int pos=1;
	for (int i=1;i<maxn;i++) {
		while (d[pos].first==i&&pos<=n) {
			mx=max(mx,d[pos].second); pos++;
		}
		fa[i][0]=mx;
	}
	for (int j=1;j<=19;j++)
	for (int i=1;i<maxn;i++)
		fa[i][j]=fa[fa[i][j-1]][j-1];
	while (m--) {
		read(x); read(y); ans=0;
		x++; y++;
		for (int i=19;i>=0;i--)
			if (fa[x][i]<y) x=fa[x][i],ans+=1<<i;
		if (x>=y);
		else if (fa[x][0]>=y) ans++;
		else ans=-1;
		printf("%d\n",ans);
	}
	return 0;
}