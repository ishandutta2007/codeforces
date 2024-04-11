#include<set>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 500000;
struct node{
	int x, y;
	node(int _x=0, int _y=0):x(_x), y(_y){}
}Pnt[MAXN + 5];
bool cmp1(node a, node b) {
	if( a.x == b.x ) return a.y < b.y;
	else return a.x < b.x;
}
bool cmp2(node a, node b) {
	if( a.y == b.y ) return a.x < b.x;
	else return a.y < b.y;
}
bool operator < (node a, node b) {
	if( a.x == b.x ) return a.y < b.y;
	else return a.x < b.x;
}
int fa[MAXN + 5];
int Find(int x) {
	if( fa[x] == x ) return x;
	else return fa[x] = Find(fa[x]);
}
void Union(int x, int y) {
	if( Find(x) != Find(y) )
		fa[Find(x)] = Find(y);
}
int main() {
	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	for(int i=1;i<=q;i++)
		scanf("%d%d", &Pnt[i].x, &Pnt[i].y);
	for(int i=0;i<=n+m;i++)
		fa[i] = i;
	Union(1, 1+n);
	sort(Pnt+1, Pnt+q+1, cmp1);
	for(int i=2;i<=q;i++)
		if( Pnt[i].x == Pnt[i-1].x ) Union(Pnt[i].y+n, Pnt[i-1].y+n);
	sort(Pnt+1, Pnt+q+1, cmp2);
	for(int i=2;i<=q;i++)
		if( Pnt[i].y+n == Pnt[i-1].y+n ) Union(Pnt[i].x, Pnt[i-1].x);
	for(int i=1;i<=q;i++) {
		if( Pnt[i].x == 1 ) Union(Pnt[i].y+n, 0);
		else if( Pnt[i].y == 1 ) Union(Pnt[i].x, 0);
	}
	int ans1 = -1;
	for(int i=0;i<=n+m;i++)
		if( fa[i] == i ) ans1++;
	int ans2 = (Find(1) != Find(0)) - 1;
	Union(1, 0);
	for(int i=1;i<=q;i++) {
		if( Pnt[i].x != 1 && Pnt[i].y != 1 )
			Union(Pnt[i].x, Pnt[i].y+n);
	}
	for(int i=0;i<=n+m;i++)
		if( fa[i] == i ) ans2++;
	printf("%d\n", min(ans1, ans2));
}