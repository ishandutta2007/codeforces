#include <bits/stdc++.h>
using namespace std;

int Solve(vector<vector<int>> A, int x) {
    int N = (int) A.size();
    vector<vector<int>> dp(N, vector<int>(N, 1e9));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
        	if (i + j == 0) dp[i][j] = 0;
			if (i > 0) dp[i][j] = min(dp[i][j], dp[i - 1][j]);
			if (j > 0) dp[i][j] = min(dp[i][j], dp[i][j - 1]);
            int tmp = A[i][j], cnt = 0;
            while (tmp > 0 && tmp % x == 0) {
                cnt++;
                tmp /= x;
			}
            dp[i][j] += cnt;
        }
    }
    return dp[N - 1][N - 1];
}

string Path(vector<vector<int>> A, int x) {
	int N = (int) A.size();
    vector<vector<int>> dp(N, vector<int>(N, 1e9));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
        	if (i + j == 0) dp[i][j] = 0;
			if (i > 0) dp[i][j] = min(dp[i][j], dp[i - 1][j]);
			if (j > 0) dp[i][j] = min(dp[i][j], dp[i][j - 1]);
            int tmp = A[i][j], cnt = 0;
            while (tmp > 0 && tmp % x == 0) {
                cnt++;
                tmp /= x;
			}
            dp[i][j] += cnt;
        }
    }
    int i = N - 1, j = N - 1;
    string ANS = "";
    while (i > 0 || j > 0) {
        int tmp = A[i][j], cnt = 0;
        while (tmp > 0 && tmp % x == 0) {
            cnt++;
            tmp /= x;
        }
        if (i > 0 && dp[i][j] == dp[i - 1][j] + cnt) {
            ANS += 'D';
            i--;
            continue;
        }
        if (j > 0 && dp[i][j] == dp[i][j - 1] + cnt) {
            ANS += 'R';
            j--;
            continue;
        }
	}
	reverse(ANS.begin(), ANS.end());
    return ANS;
}

string FindZeroPath(vector<vector<int>> A) {
    int N = (int) A.size(), x = 0, y = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (A[i][j] == 0) {
                x = i, y = j;
            }
        }
    }
    string ANS = "";
    int i = 0, j = 0;
    while (i < x) ANS += 'D', i++;
    while (j < y) ANS += 'R', j++;
    while (i < N - 1) ANS += 'D', i++;
    while (j < N - 1) ANS += 'R', j++;
    return ANS;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	int N; cin >> N;
    vector<vector<int>> A(N, vector<int>(N));
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)	cin >> A[i][j];
    bool have_zero = false;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
			have_zero |= (A[i][j] == 0);
        }
    }
	int x = Solve(A, 2), y = Solve(A, 5);
    if (have_zero && x > 0 && y > 0) {
        cout << 1 << '\n';
        cout << FindZeroPath(A) << '\n';
        return 0;
    }
    cout << min(x, y) << '\n';
    if (x < y) {
        cout << Path(A, 2) << '\n';
    } else {
		cout << Path(A, 5) << '\n';
    }
    return 0;
}