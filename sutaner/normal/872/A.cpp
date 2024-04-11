#include <cstdlib>
#include <cstdio>
#include <algorithm>
#define maxn 105
using namespace std;
bool a[maxn];
bool b[maxn];
int n, m;

int main(){
    int x;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &x), a[x] = 1; 
    for (int i = 1; i <= m; i++) scanf("%d", &x), b[x] = 1; 
    for (int i = 1; i <= 9; i++){
        if (a[i] && b[i]){
            printf("%d", i);
            return 0;
        }
    }
    for (int i = 10; i < 100; i++){
        int x = i / 10;
        int y = i % 10;
        if ((a[x] && b[y]) || (a[y] && b[x])){
            printf("%d", i);
            return 0;
        } 
    }
    return 0;
}