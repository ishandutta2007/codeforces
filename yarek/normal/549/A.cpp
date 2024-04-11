#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

char s[51][51];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
	scanf("%s", s[i]);
    set<char> p = { 'f', 'a', 'c', 'e' };
    int ans = 0;
    for(int i = 1; i < n; i++)
	for(int j = 1; j < m; j++)
	{
	    set<char> k = { s[i][j], s[i-1][j], s[i][j-1], s[i-1][j-1] };
	    if(k == p) ans++;
	}
    printf("%d\n", ans);
}