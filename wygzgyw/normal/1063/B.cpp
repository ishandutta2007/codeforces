#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; int f=1; char ch=getchar();
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=2010;
int n,m,a,b,x,y,vis[maxn][maxn],ans;
int dis[maxn][maxn],d,l[4]={0,0,1,0};
char s[maxn][maxn];
int fx[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
queue<pair<int,int> > q;
int main() {
	read(n); read(m);
	read(a); read(b); d=b;
	read(x); read(y);
	for (int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	memset(dis,0x7f7f7f7f,sizeof(dis));
	q.push(make_pair(a,b));
	vis[a][b]=1; dis[a][b]=0;
	while (!q.empty()) {
		pair<int,int> t=q.front(); q.pop();
		a=t.first; b=t.second; vis[a][b]=0;
		for (int i=0;i<4;i++) {
			int A=a+fx[i][0],B=b+fx[i][1];
			if (s[A][B]=='.'&&dis[A][B]>dis[a][b]+l[i]) {
				dis[A][B]=dis[a][b]+l[i];
				if (!vis[A][B]) q.push(make_pair(A,B)),vis[A][B]=1;
			}
		}
	}
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++) {
		if (dis[i][j]!=0x7f7f7f7f) {
			if (dis[i][j]<=x&&j-d+dis[i][j]<=y) ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}