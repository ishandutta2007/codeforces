#include <bits/stdc++.h>

using namespace std;

const int MAXN = 105;

int nTest, n, m;
char ans[MAXN][MAXN];

int main() {
    scanf("%d", &nTest);
    while (nTest--) {
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j)
                ans[i][j] = ((i + j) % 2) ? 'W' : 'B';
            ans[i][m] = 0;
        }

        if (n%2 == 0 && m%2 == 0) 
            ans[0][m-1] = 'B';
        else
            ans[n-1][m-1] = 'B';
        
        for(int i = 0; i < n; ++i)
            printf("%s\n", ans[i]);            
    }

    return 0;
}