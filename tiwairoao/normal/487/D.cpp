#include <bits/stdc++.h>
using namespace std;

const int B = 3000;
const int N = 100000;

struct point{
	int x, y;
	friend bool operator == (const point &a, const point &b) {
		return a.x == b.x && a.y == b.y;
	}
};

int n, m, q; char s[N + 5][15];
vector<point>v[N + 5]; int id[N + 5][15], bcnt;
point to[N + 5][15];

bool vis[N + 5][15];
point get(const point &p, const point &lst, const int &i) {
	if( id[p.x][p.y] != i ) return p;
	if( vis[p.x][p.y] ) return to[p.x][p.y];

	vis[p.x][p.y] = true;
	if( s[p.x][p.y] == '^' ) return to[p.x][p.y] = get((point){p.x - 1, p.y}, p, i);
	else if( s[p.x][p.y] == '>' ) {
		if( lst.y == p.y + 1 ) return to[p.x][p.y] = (point){-1, -1};
		else return to[p.x][p.y] = get((point){p.x, p.y + 1}, p, i);
	} else {
		if( lst.y == p.y - 1 ) return to[p.x][p.y] = (point){-1, -1};
		else return to[p.x][p.y] = get((point){p.x, p.y - 1}, p, i);
	}
}
void update(int x) {
	for(auto p : v[x]) get(p, (point){-1, -1}, x);
	for(auto p : v[x]) vis[p.x][p.y] = false;
}
void build() {
	int nw = B;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) {
		if( nw == B ) bcnt++, nw = 0;
		v[id[i][j] = bcnt].push_back((point){i, j}), nw++;
	}
	for(int i=1;i<=bcnt;i++) update(i);
}
point query(point p) {
	point lst = (point){-1, -1};
	while( p.x != -1 && p.y != -1 && id[p.x][p.y] ) {
		if( lst == to[p.x][p.y] ) return (point){-1, -1};
		lst = p, p = to[p.x][p.y];
	}
	return p;
}

int main() {
	scanf("%d%d%d", &n, &m, &q);
	for(int i=1;i<=n;i++) scanf("%s", s[i] + 1);
	build();

	for(int i=1;i<=q;i++) {
		char opt[2]; point p;
		scanf("%s%d%d", opt, &p.x, &p.y);
		if( opt[0] == 'A' ) {
			point ans = query(p);
			printf("%d %d\n", ans.x, ans.y);
		} else {
			char str[2]; scanf("%s", str);
			s[p.x][p.y] = str[0], update(id[p.x][p.y]);
		}
	}

	// cerr << clock() << endl;
}