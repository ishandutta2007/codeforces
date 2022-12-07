#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <set>
#define maxn 105
using namespace std;

set<int> save;
bool vis[maxn];
int main(){
    int n, m, x, y;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++){
        scanf("%d%d", &x, &y);
        x--, y--;
        for (int i = 1; i < maxn; i++){
            if (x / i != y) vis[i] = 1;
        }
    }
    for (int i = 1; i < maxn; i++){
        if (!vis[i]) save.insert((n - 1) / i + 1);
    }
    if (save.size() > 1) printf("-1");
    else printf("%d", *(save.begin()));
    return 0;
}