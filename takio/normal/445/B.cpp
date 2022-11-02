#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int fa[60];

int main()
{
    int n, m, x, y;
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        cin >> x >> y;
        while (fa[x]) x = fa[x];
        while (fa[y]) y = fa[y];
        if (x != y)
            fa[x] = y;
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
        if(fa[i]) res++;
    cout << (1LL << res);
}