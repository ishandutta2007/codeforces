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
#define y1 adjf
#define ws wejgnjn
#define left fhgfj

const int inf = 1e8;

int n, m;
vector<vector<int> > d[3];
vector<vector<char> > f;
deque<pair<int, int> > q[3];

auto valid = [](char c)->bool{ret (c >= '0' && c <= '9') || c == '.' || c == '#';};

char myget(){
	char c = getc(stdin);
	while(!valid(c))c = getc(stdin);
	ret c;
}

void bfs(int id){
	while(!q[id].empty()){
		pair<int, int> v = q[id].front(); q[id].pop_front();
		int x = v.X, y = v.Y;
		if(x > 0 && f[x - 1][y] != '#' && d[id][x - 1][y] == inf){if(isdigit(f[x - 1][y])){d[id][x - 1][y] = d[id][x][y]; q[id].push_front(mk(x - 1, y));}else{d[id][x - 1][y] = d[id][x][y] + 1; q[id].pb(mk(x - 1, y));}}
		if(y > 0 && f[x][y - 1] != '#' && d[id][x][y - 1] == inf){if(isdigit(f[x][y - 1])){d[id][x][y - 1] = d[id][x][y]; q[id].push_front(mk(x, y - 1));}else{d[id][x][y - 1] = d[id][x][y] + 1; q[id].pb(mk(x, y - 1));}}
		if(x < n - 1 && f[x + 1][y] != '#' && d[id][x + 1][y] == inf){if(isdigit(f[x + 1][y])){d[id][x + 1][y] = d[id][x][y]; q[id].push_front(mk(x + 1, y));}else{d[id][x + 1][y] = d[id][x][y] + 1; q[id].pb(mk(x + 1, y));}}
		if(y < m - 1 && f[x][y + 1] != '#' && d[id][x][y + 1] == inf){if(isdigit(f[x][y + 1])){d[id][x][y + 1] = d[id][x][y]; q[id].push_front(mk(x, y + 1));}else{d[id][x][y + 1] = d[id][x][y] + 1; q[id].pb(mk(x, y + 1));}}
	}
}

char nw[3];
bool was[3] = {false, false, false};

set<pair<int, int> > es;

int main(){
	scanf("%d%d", &n, &m);
	f.rs(n);
	F(i, 0, 3){d[i].rs(n); nw[i] = '1' + i;}
	F(i, 0, n){
		f[i].rs(m);
		F(k, 0, 3){d[k][i].rs(m); d[k][i].asg(m ,inf);}
		F(j, 0, m){
			f[i][j] = myget();
			if(!isdigit(f[i][j]))cont;
			if(i > 0 && isdigit(f[i - 1][j])){
				char fc = min(f[i][j], f[i - 1][j]), sc = max(f[i][j], f[i - 1][j]);
				if(fc == '1' && sc == '3'){nw[2] = '1';}
				if(fc == '2' && sc == '3'){nw[1] = '3';}
				if(fc == '1' && sc == '2'){nw[1] = '1';}
				if(fc != sc)es.ins(mk(fc - '1', sc - '1'));
			}
			if(j > 0 && isdigit(f[i][j - 1])){
				char fc = min(f[i][j], f[i][j - 1]), sc = max(f[i][j], f[i][j - 1]);
				if(fc == '1' && sc == '3'){nw[2] = '1';}
				if(fc == '2' && sc == '3'){nw[1] = '3';}
				if(fc == '1' && sc == '2'){nw[1] = '1';}
				if(fc != sc)es.ins(mk(fc - '1', sc - '1'));
			}
		}
	}
	if(es.size() >= 2){
		F(i, 0, 3)
			nw[i] = '1';
	}
	F(i, 0, n){
		F(j, 0, m){
			if(f[i][j] >= '0' && f[i][j] <= '9'){f[i][j] = nw[f[i][j] - '1']; was[f[i][j] - '1'] = true; q[f[i][j] - '1'].pb(mk(i, j)); d[f[i][j] - '1'][i][j] = 0;}
		}
	}
	int cw = 0;
	F(i, 0, 3)
		if(was[i])cw++;
	if(cw == 1){printf("0"); ret 0;}
	int ans = inf;
	F(k, 0, 3)bfs(k);
	F(i, 0, n){
		F(j, 0, m){
			if(f[i][j] == '#')cont;
			int curr = 0;
			F(k, 0, 3)if(was[k])curr += d[k][i][j] + ((f[i][j] == '.') ? -1 : 0);
			if(f[i][j] == '.')curr++;
			if(curr < ans){ans = curr;}
		}
	}
	if(ans >= 2e6 + 300){printf("-1");}
	else{printf("%d", ans);}
	ret 0;
}