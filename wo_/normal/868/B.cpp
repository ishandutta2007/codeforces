#include<cstdio>
#include<algorithm>

using namespace std;

bool ok[12][12];

int h, m, s;
int t1, t2;

int f(int x){
	if(x == 12) x = 0;
	return x;
}

void input(){
	scanf("%d%d%d", &h, &m, &s);
	scanf("%d%d", &t1, &t2);
	h = f(h);
	t1 = f(t1);
	t2 = f(t2);
}

int nxt(int x){
	int y = x + 1;
	if(y == 12) y = 0;
	return y;
}

bool solve(){
	for(int i = 0; i < 12; ++i){
		for(int j = 0; j < 12; ++j){
			if(i == j) ok[i][j] = true;
			if(j == i - 1) ok[i][j] = true;
			if(i == j - 1) ok[i][j] = true;
			if(i == 0 && j == 11) ok[i][j] = true;
			if(i == 11 && j == 0) ok[i][j] = true;
		}
	}
	ok[h][nxt(h)] = false;
	ok[nxt(h)][h] = false;
	m /= 5;
	ok[m][nxt(m)] = false;
	ok[nxt(m)][m] = false;
	s /= 5;
	ok[s][nxt(s)] = false;
	ok[nxt(s)][s] = false;
	for(int k = 0; k < 12; ++k){
		for(int i = 0; i < 12; ++i){
			for(int j = 0; j < 12; ++j){
				ok[i][j] |= (ok[i][k] & ok[k][j]);
			}
		}
	}
	return ok[t1][t2];
}

int main(){
	input();
	bool ans = solve();
	if(ans) printf("YES\n");
	else printf("NO\n");
	return 0;
}