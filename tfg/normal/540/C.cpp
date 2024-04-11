#include <iostream>
#include <string>

int n, m;
std::string board[550];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool valid(int r, int c)
{
	return 0 <= r && r < n && 0 <= c && c < m;
}

bool visit[550][550];

void dfs(int r, int c)
{
	if(visit[r][c] || !valid(r, c) || board[r][c] == 'X')
		return;
	//std::cout << "Got to (" << r << ", " << c << ")\n";
	visit[r][c] = true;
	for(int i = 0; i < 4; i++)
		dfs(r + dx[i], c + dy[i]);
}

bool solve(int r, int c)
{
	bool validd = false;
	for(int i = 0; i < 4; i++)
		validd = validd || (valid(r + dx[i], c + dy[i]) && visit[r + dx[i]][c + dy[i]]);
	int count = 0;
	for(int i = 0; i < 4; i++)
		count += (valid(r + dx[i], c + dy[i]) && visit[r + dx[i]][c + dy[i]]) ? 1 : 0;
	if(board[r][c] == 'X')
		return validd;
	else
		return validd && count > 1;
}

int main()
{
	std::cin >> n >> m;
	for(int i = 0; i < n; i++)
		std::cin >> board[i];
	int s[2], e[2];
	std::cin >> s[0] >> s[1] >> e[0] >> e[1];
	char x = board[s[0] - 1][s[1] - 1];
	board[s[0] - 1][s[1] - 1] = '.';
	dfs(s[0] - 1, s[1] - 1);
	board[s[0] - 1][s[1] - 1] = x;
	if(solve(e[0] - 1, e[1] - 1))
		std::cout << "YES\n";
	else
		std::cout << "NO\n";
}