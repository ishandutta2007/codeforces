#include <cstdio>

int val[101][101];
char s[102];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
    {
	scanf("%s", s);
	for(int j = 0; j < m; j++)
	    val[i][j] = (s[j] == 'W' ? 1 : -1);
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
	for(int j = 0; j < m; j++)
	    if(val[i+1][j] + val[i][j+1] - val[i+1][j+1] != val[i][j]) ans++;
    printf("%d\n", ans);
}