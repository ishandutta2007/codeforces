#include <cstdlib>
#include <cstdio>
#include <algorithm>
#define maxn 400005
using namespace std;
int ufs[maxn];
int siz[maxn];
int line[maxn];
int n;
int find_root(int x){
    return ufs[x] = (ufs[x] == x) ? x : find_root(ufs[x]);
}

int main(){
    /*freopen("D.in", "r", stdin);
    freopen("D.out", "w", stdout);*/
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &line[i]);
    printf("1");
    for (int i = 1; i <= n; i++){
        int op = line[i];
        ufs[op] = op;
        siz[op] = 1;
        if (ufs[op - 1]) ufs[op - 1] = op, siz[op] += siz[op - 1];
        if (ufs[op + 1]) ufs[op] = op + 1, siz[find_root(op + 1)] += siz[op];
        int sum = (ufs[n]) ? siz[n] : 0;
        printf(" %d", i - sum + 1);
    }
    return 0;
}