#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 12;
const int MAXM = 2000;
int a[MAXN + 5][MAXM + 5], n, m;
int f[1<<MAXN], g[1<<MAXN], h[1<<MAXN], lg[1<<MAXN];
int lowbit(int x) {return x & -x;}
struct node{
	int key, id;
	friend bool operator < (node a, node b) {
		return a.key > b.key;
	}
}arr[MAXM + 5];
bool tag[MAXM + 5];
void solve() {
	scanf("%d%d", &n, &m);
	for(int j=1;j<=m;j++)
		tag[j] = false, arr[j].key = 0, arr[j].id = j;
	for(int i=0;i<n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d", &a[i][j]), arr[j].key = max(arr[j].key, a[i][j]);
	sort(arr + 1, arr + m + 1);
	for(int i=1;i<=m&&i<=n;i++)
		tag[arr[i].id] = true;
	int tot = (1<<n);
	for(int j=0;j<tot;j++) f[j] = 0;
	for(int j=0;j<n;j++) lg[1<<j] = j;
	for(int i=1;i<=m;i++) {
		if( !tag[i] ) continue;
		for(int j=0;j<tot;j++) h[j] = 0;
		for(int j=1;j<=n;j++) {
			for(int k=0;k<tot;k++)
				g[k] = f[k];
			for(int k=0;k<tot;k++) {
				int p = (tot - 1)^k;
				while( p ) {
					int x = lowbit(p), y = lg[x];
					g[k|x] = max(g[k|x], g[k] + a[y][i]);
					p -= x;
				}
			}
			int tmp = a[0][i];
			for(int k=0;k<n-1;k++)
				a[k][i] = a[k + 1][i];
			a[n - 1][i] = tmp;
			for(int j=0;j<tot;j++)
				h[j] = max(h[j], g[j]), g[j] = 0;
		}
		for(int j=0;j<tot;j++) f[j] = h[j];
	}
	printf("%d\n", f[tot - 1]);
}
int main() {
	int t; scanf("%d", &t);
	while( t-- ) solve();
}