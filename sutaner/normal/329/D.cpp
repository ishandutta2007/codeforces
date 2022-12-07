#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 120
using namespace std;

namespace Test{
	int n, m, T;
	char a[maxn][maxn];
	inline bool ok(int x, int y){
		return 1 <= x && x <= n && 1 <= y && y <= m;
	}
	inline void print(){
		rep(i, 1, n) printf("%s\n", a[i] + 1); printf("\n");
	}
	int judge(int x, int y){ 
		int ans = 0;
		while (ok(x, y) && a[x][y] != '.'){ 
			if (a[x][y] == '^') { 
				a[x][y] = '.';
				x--; int f = 0;
				while (x >= 1 && a[x][y] == '.') x--, f = 1; 
				a[x + 1][y] = '^';
				ans += f;
			}
			else if (a[x][y] == '>') { 
				a[x][y] = '.';
				y++; int f = 0;
				while (y <= m && a[x][y] == '.') y++, f = 1; 
				a[x][y - 1] = '>';
				ans += f;
			}
			else if (a[x][y] == 'v') { 
				a[x][y] = '.';
				x++; int f = 0;
				while (x <= n && a[x][y] == '.') x++, f = 1;
				a[x - 1][y] = 'v';
				ans += f;
			}
			else if (a[x][y] == '<') { 
				a[x][y] = '.';
				y--; int f = 0;
				while (y >= 1 && a[x][y] == '.') y--, f = 1; 
				a[x][y + 1] = '<';
				ans += f;
			}
			else assert(false);
			if (T) print();
		}
		return ans;
	}
	void work(){
		scanf("%d%d%d", &n, &m, &T);
		rep(i, 1, n) scanf("%s", a[i] + 1);
		int x, y;
		scanf("%d%d", &x, &y); 
		int ans = judge(x, y);
		if (ans >= 100000) printf("Your score is: %d, NB!!!", ans);
		else printf("Your score is: %d, come on!!!", ans);
	}
}

namespace Construct{
	void work(){
		int n, m;
		scanf("%d%d", &n, &m);
		if (n == 5){
			printf(">...v\n.>.v.\n.....\n...<.\n^^..<\n5 1\n");
		}
		if (n == 3){
			printf(">.v\n...\n^.<\n");
			printf("1 1\n");
		}
		if (n == 100){
			printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>..v\n^.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
			rep(i, 2, 50) printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.v\n^.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
			printf("1 1\n");
		}
	}
}

int main(){
	Construct :: work();
	return 0;
}