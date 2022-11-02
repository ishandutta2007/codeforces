#include <bits/stdc++.h>
using namespace std;

int n, m;
char g[102][102];
int conf[102][102];
bool err[102];

int main() {
    int i, j;
    scanf(" %d %d", &n, &m);
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            scanf(" %c", &g[i][j]);
    int cont = 0;
    do {
        for(i = 0; i < n - 1; i++) {
            bool res = false;
            for(j = 0; j < m; j++) {
                if(err[j]) continue;
                if(g[i + 1][j] > g[i][j]) break;
                if(g[i][j] == g[i + 1][j]) continue;
                err[j] = true;
                cont++;
                res = true;
                break;
            }
            if(res) break;
        }
    } while(i < n - 1); // apagou alguma
    printf("%d\n", cont);
    return 0;
}