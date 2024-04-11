#include <iostream>
#include <iomanip>

typedef long double ld;

ld memo[101][101][101];
bool visit[101][101][101];

ld dp(int a, int b, int c)
{
	if(a < 0 || b < 0 || c < 0)
		return 0;
	if(a == 0)
		return 0;
	if(a > 0 && b + c == 0)
		return 1.0;
	ld &ans = memo[a][b][c];
	if(visit[a][b][c])
		return ans;
	ans = 0;
	visit[a][b][c] = true;
	ld den = a * b + a * c + b * c;
	ans = (a * b * dp(a, b - 1, c) + a * c * dp(a - 1, b, c) + b * c * dp(a, b, c - 1)) / den;
	return ans;
}

int main()
{
	int r, s, p;
	std::cin >> r >> s >> p;
	std::cout << std::fixed << std::setprecision(20);
	std::cout << dp(r, s, p) << ' ' << dp(s, p, r) << ' ' << dp(p, r, s) << '\n';
}