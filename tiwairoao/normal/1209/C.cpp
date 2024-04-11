#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 200000;
struct node{
	int id, num;
	friend bool operator < (node a, node b) {
		return (a.num == b.num) ? a.id < b.id : a.num < b.num;
	}
}a[MAXN + 5];
char d[MAXN + 5];
int ans[MAXN + 5];
void solve() {
	int n; scanf("%d%s", &n, d + 1);
	for(int i=1;i<=n;i++)
		a[i].id = i, a[i].num = d[i] - '0';
	a[n + 1].num = -1;
	sort(a + 1, a + n + 1);
	int pos = a[1].id;
	for(int i=1;i<=n;i++)
		if( a[i].id >= pos ) {
			ans[a[i].id] = 1;
			pos = a[i].id;
		}
		else {
			int l = i;
			while( a[l].num == a[i].num ) l++;
			int tmp = l;
			while( a[l-1].id >= pos ) ans[a[--l].id] = 1;
			for(int j=i;j<l;j++)
				ans[a[j].id] = 2;
			int pos = a[l - 1].id;
			for(int j=tmp;j<=n;j++)
				if( a[j].id >= pos ) {
					ans[a[j].id] = 2;
					pos = a[j].id;
				}
				else {
					puts("-");
					return ;
				}
			break;
		}
	for(int i=1;i<=n;i++)
		printf("%d", ans[i]);
	puts("");
}
int main() {
	int t; scanf("%d", &t);
	while( t-- ) solve();
}