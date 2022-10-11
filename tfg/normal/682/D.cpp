#include <iostream>
#include <cstring>

int n, m, k;
int memo[1010][1010][11][2];

std::string s, t;

int dp(int a, int b, int got, int is)
{
	int &ans = memo[a][b][got][is];
	if(ans != -1)
		return ans;
	ans = 0;
	if(got == k && is == 0)
		return ans;
	if(a == s.size() || b == t.size())
		return ans;
	if(s[a] == t[b])
		ans = std::max(ans, 1 + dp(a + 1, b + 1, got + 1 - is, 1));
	ans = std::max(ans, dp(a + 1, b, got, 0));
	ans = std::max(ans, dp(a, b + 1, got, 0));
	return ans;
}

int main()
{
	std::cin >> n >> m >> k >> s >> t;
	memset(memo, -1, sizeof memo);
	std::cout << dp(0, 0, 0, 0) << '\n';
}