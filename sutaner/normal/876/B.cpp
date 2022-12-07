#include <cstdlib>
#include <cstdio>
#include <algorithm>
#define maxn 100005
using namespace std;
int line[maxn];
int n, m, k;
int mod[maxn];


int main(){
    scanf("%d%d%d", &n, &k, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &line[i]);
    for (int i = 1; i <= n; i++) mod[line[i] % m]++;
    int f = -1;
    for (int i = 0; i < m; i++){
        if (mod[i] >= k){
            f = i;
            break;
        }
    }
    if (f == -1){
        printf("No");
    }
    else{
        printf("Yes\n");
        int ct = 0;
        for (int i = 1; i <= n; i++){
            if (line[i] % m == f){
                printf("%d ", line[i]);
                ct++;
                if (ct == k) return 0;
            }
        }
    }
    return 0;
}