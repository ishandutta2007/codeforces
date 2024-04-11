#include<bits/stdc++.h>

using namespace std;
typedef long long lint;
typedef long double ldb;
typedef unsigned long long uli;

#define X first
#define Y second
#define F(i, l, r) for(auto i = l; i != r; i++)
#define Df(i, l, r) for(auto i = l; i != r; i--)
#define I(i, a) for(auto i : a)
#define pb push_back
#define rs resize
#define mk make_pair
#define asg assign
#define all(x) x.begin(),x.end()
#define ret return
#define cont continue
#define brk break
#define ins insert
#define era erase
#define fi0(x) memset(x, 0, sizeof(x))
#define finf(x) memset(x, 127, sizeof(x))
#define y1 adjf
#define tm dhgdg

const int MAXN = 1e3 + 3;
const int MAXK = 1e6 + 6;
const int inf = 1e9 + 9;

char f[MAXN][MAXN];
int d[MAXN][MAXN];
pair<int, int> q[2 * MAXN * MAXN + 69];
int qh = 0, qt = 0;
int n, m, k;
int x, y;

void fail(){
	printf("IMPOSSIBLE");
	exit(0);
}

char myget(){
	char c = getc(stdin);
	while(c != '.' && c != '*' && c != 'X')c = getc(stdin);
	ret c;
}

void bfs(){
	while(qh < qt){
		int i = q[qh].X, j = q[qh].Y;
		qh++;
		if(i > 0 && f[i - 1][j] == '.' && d[i - 1][j] == inf){q[qt++] = mk(i - 1, j); d[i - 1][j] = d[i][j] + 1;}
		if(j > 0 && f[i][j - 1] == '.' && d[i][j - 1] == inf){q[qt++] = mk(i, j - 1); d[i][j - 1] = d[i][j] + 1;}
		if(i < n - 1 && f[i + 1][j] == '.' && d[i + 1][j] == inf){q[qt++] = mk(i + 1, j); d[i + 1][j] = d[i][j] + 1;}
		if(j < m - 1 && f[i][j + 1] == '.' && d[i][j + 1] == inf){q[qt++] = mk(i, j + 1); d[i][j + 1] = d[i][j] + 1;}
	}
}

char buf[MAXK + 69];
int bufsz = 0;

void push(char c){
	buf[bufsz++] = c;
}

bool can(int i, int j, int len){
	if(d[i][j] == inf)ret false;
	if(len%2 != d[i][j]%2)ret false;
	if(d[i][j] > len)ret false;
	ret true;
}

int main(){
	scanf("%d%d%d", &n, &m, &k);
	if(k&1)fail();
	F(i, 0, n){
		F(j, 0, m){
			f[i][j] = myget();
			d[i][j] = inf;
			if(f[i][j] == 'X'){
				f[i][j] = '.';
				x = i; y = j;
				d[i][j] = 0;
				q[qt++] = mk(i, j);
			}
		}
	}
	bfs();
	int cx = x, cy = y;
	F(i, 0, k){
		if(cx < n - 1 && can(cx + 1, cy, k - i - 1)){push('D'); cx++; cont;}
		if(cy > 0 && can(cx, cy - 1, k - i - 1)){push('L'); cy--; cont;}
		if(cy < m - 1 && can(cx, cy + 1, k - i - 1)){push('R'); cy++; cont;}
		if(cx > 0 && can(cx - 1, cy, k - i - 1)){push('U'); cx--; cont;}
		fail();
	}
	F(i, 0, bufsz)putc(buf[i], stdout);
	ret 0;
}