#include <iostream>
#include <stack>

typedef long long ll;

std::string str;

int memo[10010][110][2];
bool vis[10010][110][2];
char lul;
int to[10010];

int dp(int on, int left, int max) {
	int &ans = memo[on][left][max];
	if(vis[on][left][max]) {
		return ans;
	}
	vis[on][left][max] = true;
	if(str[on] != '(') {
		if(left == 0) {
			return ans = str[on] - '0';
		} else {
			return ans = max ? -1e9 : 1e9;
		}
	}
	if(max) {
		ans = -1e9;
		int n = left - (lul == '-');
		for(int i = 0; i <= n; i++) {
			ans = std::max(ans, dp(on + 1, i, 1) - dp(to[on + 1] + 1, n - i, 0));
		}
		n = left - (lul == '+');
		for(int i = 0; i <= n; i++) {
			ans = std::max(ans, dp(on + 1, i, 1) + dp(to[on + 1] + 1, n - i, 1));
		}
	} else {
		ans = 1e9;
		int n = left - (lul == '-');
		for(int i = 0; i <= n; i++) {
			ans = std::min(ans, dp(on + 1, i, 0) - dp(to[on + 1] + 1, n - i, 1));
		}
		n = left - (lul == '+');
		for(int i = 0; i <= n; i++) {
			ans = std::min(ans, dp(on + 1, i, 0) + dp(to[on + 1] + 1, n - i, 0));
		}
	}
	return ans;
}

int main() {
	std::stack<int> s;
	std::cin >> str;
	int p, m;
	std::cin >> p >> m;
	for(int i = 0; i < str.size(); i++) {
		if('0' <= str[i] && str[i] <= '9') {
			to[i] = i + 1;
		} else if(str[i] == '(') {
			s.push(i);
		} else if(str[i] == ')') {
			to[s.top()] = i + 1;
			s.pop();
		}
	}
	lul = p < m ? '+' : '-';
	std::cout << dp(0, std::min(p, m), 1) << '\n';
}