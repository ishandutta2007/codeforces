#include <bits/stdc++.h>
using namespace std;

const int CC = 500*500 + 1;
int size[CC];
int covered[CC];
bool used[CC];
const int N = 502;
char s[N][N];
int cc[N][N];

void dfs(int x, int y, int nr)
{
    if(s[x][y] != '.' || cc[x][y]) return;
    cc[x][y] = nr;
    size[nr]++;
    dfs(x - 1, y, nr);
    dfs(x + 1, y, nr);
    dfs(x, y - 1, nr);
    dfs(x, y + 1, nr);
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++)
        scanf("%s", s[i] + 1);
    int m = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(s[i][j] == '.' && !cc[i][j])
                dfs(i, j, ++m);
    vector<int> vec;
    vec.reserve(k * k);
    int ans = 0;
    for(int i = 1; i + k - 1 <= n; i++)
    {
        for(int x = 0; x < k; x++)
            for(int y = 0; y < k; y++)
                covered[cc[i+x][y+1]]++;
        for(int j = 1; j + k - 1 <= n; j++)
        {
            vec.clear();
            int sum = k * k;
            for(int l = 0; l < k; l++)
            {
                vec.push_back(cc[i-1][j+l]);
                vec.push_back(cc[i+k][j+l]);
                vec.push_back(cc[i+l][j-1]);
                vec.push_back(cc[i+l][j+k]);
            }
            for(const auto &x: vec)
                if(x && !used[x])
                {
                    sum += size[x] - covered[x];
                    used[x] = true;
                }
            ans = max(ans, sum);
            for(const auto &x: vec)
                used[x] = false;
            for(int l = 0; l < k; l++)
            {
                covered[cc[i+l][j]]--;
                covered[cc[i+l][j+k]]++;
            }
        }
        for(int x = 0; x < k; x++)
            for(int y = 0; y < k; y++)
                covered[cc[i+x][n-y]] = 0;
    }
    printf("%d\n", ans);
}