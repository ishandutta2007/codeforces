#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;

const int N = 100100;
int n;
char s[N], t[N];
int ans;

bool solve(int idx)
{
	while(idx + 1 < n && s[idx] == t[idx + 1])
		idx++;
	idx++;
	while(idx < n && s[idx] == t[idx])
		idx++;
	return idx == n;
}

int main()
{
//	freopen("input.txt", "r", stdin);

	scanf("%d %s %s", &n, s, t);
	int idx = 0;
	while(s[idx] == t[idx]) idx++;
	if (solve(idx)) ans++;
	swap(s, t);
	if (solve(idx)) ans++;
	printf("%d\n", ans);

	return 0;
}