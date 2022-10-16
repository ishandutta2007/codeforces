#include <bits/stdc++.h>

using namespace std;

const int N = 506;

int res, n;
char s[N][N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; ++i)
    	cin >> s[i];

    for(int i = 1; i < n - 1; ++i)
    for(int j = 1; j < n - 1; ++j)
    	if (s[i][j] == 'X' &&
    		s[i+1][j+1] == 'X' &&
    		s[i+1][j-1] == 'X' &&
    		s[i-1][j+1] == 'X' &&
    		s[i-1][j-1] == 'X') ++res;
    cout << res;
}