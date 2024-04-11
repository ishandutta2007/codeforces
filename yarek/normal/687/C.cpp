#include <bits/stdc++.h>
using namespace std;

const int K = 501;
bool tab[K][K][K];
int c[K];

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++)
        scanf("%d", c + i);
    tab[0][0][0] = true;
    for(int i = 1; i <= n; i++)
    {
        int C = c[i-1];
        for(int j = 0; j <= k; j++)
            for(int l = 0; l <= j; l++)
                if(tab[i-1][j][l] || (j-C >= 0 && tab[i-1][j-C][l]) || (l-C >= 0 && tab[i-1][j-C][l-C]))
                    tab[i][j][l] = true;
    }
    vector<int> ans;
    for(int i = 0; i <= k; i++)
        if(tab[n][k][i]) ans.push_back(i);
    printf("%d\n", ans.size());
    for(auto x: ans)
        printf("%d ", x);
    puts("");
}