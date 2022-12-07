#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <set>
#define maxn 2005
using namespace std;
set<int> save;
int x[maxn];
int y[maxn];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &x[i]), save.insert(x[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &y[i]), save.insert(y[i]);
    int ans = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (save.count(x[i] ^ y[j])) ans++;
        }
    }
    if (ans & 1) printf("Koyomi");
    else printf("Karen");
    return 0;
}