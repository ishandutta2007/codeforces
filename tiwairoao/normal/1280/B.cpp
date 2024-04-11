#include <cstdio>

const int MAXN = 60;

char s[MAXN + 5][MAXN + 5];
int r, c;

bool check0() {
	for(int i=1;i<=r;i++)
		for(int j=1;j<=c;j++)
			if( s[i][j] != 'A' )
				return false;
	return true;
}

bool check1() {
	bool flag = true;
	for(int i=1;i<=r;i++)
		if( s[i][1] != 'A' ) {
			flag = false;
			break;
		}
	if( flag ) return true;
	flag = true;
	for(int i=1;i<=r;i++)
		if( s[i][c] != 'A' ) {
			flag = false;
			break;
		}
	if( flag ) return true;
	flag = true;
	for(int j=1;j<=c;j++)
		if( s[1][j] != 'A' ) {
			flag = false;
			break;
		}
	if( flag ) return true;
	flag = true;
	for(int j=1;j<=c;j++)
		if( s[r][j] != 'A' ) {
			flag = false;
			break;
		}
	if( flag ) return true;
	return false;
}

bool check2() {
	if( s[1][1] == 'A' || s[1][c] == 'A' || s[r][1] == 'A' || s[r][c] == 'A' )
		return true;
	else {
		for(int i=1;i<=r;i++) {
			bool flag = true;
			for(int j=1;j<=c;j++) {
				if( s[i][j] != 'A' ) {
					flag = false;
					break;
				}
			}
			if( flag ) return true;
		}
		for(int j=1;j<=c;j++) {
			bool flag = true;
			for(int i=1;i<=r;i++) {
				if( s[i][j] != 'A' ) {
					flag = false;
					break;
				}
			}
			if( flag ) return true;
		}
		return false;
	}
}

bool check3() {
	for(int i=1;i<=r;i++)
		if( s[i][1] == 'A' || s[i][c] == 'A' )
			return true;
	for(int j=1;j<=c;j++)
		if( s[1][j] == 'A' || s[r][j] == 'A' )
			return true;
	return false;
}

bool check4() {
	for(int i=1;i<=r;i++)
		for(int j=1;j<=c;j++)
			if( s[i][j] == 'A' ) return true;
	return false;
}

void solve() {
	scanf("%d%d", &r, &c);
	for(int i=1;i<=r;i++)
		scanf("%s", s[i] + 1);
	if( check0() ) puts("0");
	else if( check1() ) puts("1");
	else if( check2() ) puts("2");
	else if( check3() ) puts("3");
	else if( check4() ) puts("4");
	else puts("MORTAL");
}
int main() {
	int t; scanf("%d", &t);
	while( t-- ) solve();
}