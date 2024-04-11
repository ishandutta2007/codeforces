#include <bits/stdc++.h>
 
using namespace std;
 
#define FOE(i, s, t) for (int i = s; i <= t; i++)
#define FOR(i, s, t) for (int i = s; i < t; i++)
#define FOD(i, s, t) for (int i = s; i >= t; i--)
#define K 400001
#define LL long long
#define mp make_pair
#define pb push_back
#define M 1000000007
#define pow qjwopjqpw

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

string s; 

char dir[4] = {'L', 'R', 'D', 'U'};

bool run(int tx, int ty) {
	int cx = 0, cy = 0;
	FOR(i, 0, s.length()) {
		auto v = s[i];
		FOE(j, 0, 3) if (dir[j] == v) {
			int nx = cx + dx[j];
			int ny = cy + dy[j];
			
			if (nx != tx || ny != ty) {
				cx = nx;
				cy = ny;	
			}
		}
	}
	
	return (cx == 0 && cy == 0);
}

void solve() {
	cin >> s;
	
	int cx = 0, cy = 0;
	
	FOR(i, 0, s.length()) {
		auto v = s[i];
		
		FOE(j, 0, 3) if (dir[j] == v) {
			cx += dx[j];
			cy += dy[j];
			
			if (cx != 0 || cy != 0) {
				if (run(cx, cy)) {
					printf("%d %d\n", cx, cy);
					return;
				}	
			}
		}
	}
	puts("0 0");
}
 
int main() {
	int t; scanf("%d", &t);
	
	while (t--) solve();
}