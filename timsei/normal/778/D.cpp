#include <bits/stdc++.h>
using namespace std;

const int N = 55;

int n, m, x, y;
char s[N][N], t[N][N];

bool Rev = 0;

typedef pair <int, int> pii;
#define mp make_pair

vector <pii> ans;

void chg(int x, int y, char (*s)[N]) {
	if(s[x][y] == 'U' && s[x][y + 1] == 'L') {
		if(s[x + 1][y + 1] == 'L') {
			ans.push_back(mp(x, y + 1));
			ans.push_back(mp(x, y));
			s[x][y] = s[x + 1][y] = 'L';
			s[x][y + 1] = s[x + 1][y + 1] = 'R';
			s[x][y + 2] = 'U';
			s[x + 1][y + 2] = 'D';
			return;
		}
		else {
			chg(x + 1, y + 1, s);
			chg(x, y, s);
		}
	}
	else {
		ans.push_back(mp(x, y));
		s[x][y] = s[x + 1][y] = 'L';
		s[x][y + 1] = s[x + 1][y + 1] = 'R';
	}
}

vector < pii > solve (char (*s)[N]) {
	ans.clear();
	for(int i = 1; i <= n; ++ i) 
		for(int j = 1; j <= m; ++ j) {
			if(Rev) {
				if(s[i][j] == 'U') s[i][j] = 'L';
				else if(s[i][j] == 'L') s[i][j] = 'U';
				else if(s[i][j] == 'D') s[i][j] = 'D';
				else s[i][j] = 'R';
			}
		}
	for(int i = 1; i <= n; ++ i) for(int j = 1; j <= m; j += 2) if(s[i][j] != 'L') chg(i, j, s);
	return ans;
}

char Mp[N][N];

void rev(char (*s)[N]) {
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= m; ++ j) 
		Mp[j][i] = s[i][j];
	}
	for(int i = 1; i <= m; ++ i) {
		for(int j = 1; j <= n; ++ j)
		s[i][j] = Mp[i][j];
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++ i)
	scanf("%s", s[i] + 1);
	for(int i = 1; i <= n; ++ i)
	scanf("%s", t[i] + 1);
	if(m & 1) {
		Rev = 1;
		rev(s);
		rev(t);
		swap(n, m);
	}
	vector <pii> A = solve(s);
	vector <pii> B = solve(t);
	reverse(B.begin(), B.end());
	cout << A.size() + B.size() << endl;
	for(int i = 0; i < (int) A.size(); ++ i) {
		if(Rev) swap(A[i].first, A[i].second);
		printf("%d %d\n", A[i].first, A[i].second);
	} 
	for(int i = 0; i < (int) B.size(); ++ i) {
		if(Rev) swap(B[i].first, B[i].second);
		printf("%d %d\n", B[i].first, B[i].second);
	} 
}