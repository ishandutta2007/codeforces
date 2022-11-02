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
#define tm afhdhn

const int MAXW = 1e3 + 4;
const int md = 1e7;

char t[MAXW][MAXW];
int w, h;
int ans = 0;
int d[MAXW][MAXW];
queue<pair<int, int> > q;

char myget(){
	char c = getc(stdin);
	while(!isdigit(c) && c != 'S' && c != 'T' && c != 'E')c = getc(stdin);
	ret c;
}

void bfs(){
	while(!q.empty()){
		int x = q.front().X, y = q.front().Y;
		q.pop();
		if(x > 0 && t[x - 1][y] != 'T' && d[x - 1][y] > md){d[x - 1][y] = d[x][y] + 1; q.push(mk(x - 1, y));}
		if(y > 0 && t[x][y - 1] != 'T' && d[x][y - 1] > md){d[x][y - 1] = d[x][y] + 1; q.push(mk(x, y - 1));}
		if(x < w - 1 && t[x + 1][y] != 'T' && d[x + 1][y] > md){d[x + 1][y] = d[x][y] + 1; q.push(mk(x + 1, y));}
		if(y < h - 1 && t[x][y + 1] != 'T' && d[x][y + 1] > md){d[x][y + 1] = d[x][y] + 1; q.push(mk(x, y + 1));}
	}
}

int main(){
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d%d", &w, &h);
	F(i, 0, w){
		F(j, 0, h){
			d[i][j] = 1e9;
			t[i][j] = myget();
			if(t[i][j] == 'E'){d[i][j] = 0;	q.push(mk(i, j));}
		}
	}
	bfs();
	int _i, _j;
	F(i, 0, w)
		F(j, 0, h)
			if(t[i][j] == 'S'){_i = i; _j = j;}
	F(i, 0, w)
		F(j, 0, h)
			if(isdigit(t[i][j]) && d[i][j] <= d[_i][_j])ans += t[i][j] - '0';
	printf("%d", ans);
	ret 0;
}