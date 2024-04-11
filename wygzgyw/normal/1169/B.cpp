#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(3e5)+10;
int n,m,c[maxn];
int x[maxn],y[maxn];
bool ck(int a,int b) {
	for (int i=1;i<=m;i++)
		if (x[i]!=a&&x[i]!=b&&y[i]!=a&&y[i]!=b) return 0;
	return 1;
}
int in[maxn],cnt,mx;
vector<int> g[maxn];
map<ll,bool> t;
bool ck(int a) {
	memset(in,0,sizeof(in)); cnt=mx=0;
	for (int i=1;i<=m;i++)
		if (x[i]!=a&&y[i]!=a)
			in[x[i]]++,in[y[i]]++,cnt++;
	for (int i=1;i<=n;i++) mx=max(mx,in[i]);
	return mx==cnt;
}
ll haxi(int x,int y) {
	return (ll)(x-1)*n+y;
}
int main() {
	//freopen("1.txt","r",stdin);
	//freopen("1.out","w",stdout);
	read(n); read(m); ll tmp;
	for (int i=1;i<=m;i++) {
		read(x[i]); read(y[i]);
		if (x[i]>y[i]) swap(x[i],y[i]);
		tmp=haxi(x[i],y[i]);
		if (t[tmp]) continue;
		t[tmp]=1;
		g[x[i]].push_back(y[i]);
		g[y[i]].push_back(x[i]);
	}
	int a=0,b=0;
	for (int i=1;i<=n;i++) {
		if (g[i].size()>2) {
			if (!a) a=i;
			else if (!b) { b=i; break; }
			else { printf("No\n"); return 0; }
		} else if (g[i].size()==1) {
			if (a&&ck(g[i][0],a)) { printf("Yes\n"); return 0; }
			if (ck(g[i][0])) { printf("Yes\n"); return 0; }
			if (!a) a=i;
			else if (!b) { b=i; break; }
			else { printf("No\n"); return 0; }
		} else if (g[i].size()==2) {
			if (ck(g[i][0],g[i][1])) { printf("Yes\n"); return 0; }
			if (!a) a=i;
			else if (!b) { b=i; break; }
			else { printf("No\n"); return 0; }
		}
	}
	if (ck(a,b)) printf("Yes\n");
	else printf("No\n");
	return 0;
}