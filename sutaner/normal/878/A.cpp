#include <cstdlib>
#include <cstdio>
#include <algorithm>
#define maxn 10
using namespace std;

int num[maxn];
int two[maxn];

int main(){
    /*freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);*/
    int n;
    two[0] = 1, num[0] = 4;
    for (int i = 1; i < maxn; i++) num[i] = 4, two[i] = two[i - 1] << 1;
    scanf("%d", &n);
    char op[5];
    int x;
    for (int i = 1; i <= n; i++){
        scanf("%s%d", op, &x);
        if (op[0] == '&'){
            for (int j = 0; j < maxn; j++){
                if (!(x & two[j])) num[j] = 1;
            }
        }
        else if (op[0] == '|'){
            for (int j = 0; j < maxn; j++){
                if (x & two[j]) num[j] = 2;
            }
        }
        else if (op[0] == '^'){
            for (int j = 0; j < maxn; j++){
                if (x & two[j]){
                    if (num[j] == 1 || num[j] == 2) num[j] = 3 - num[j];
                    else num[j] = 7 - num[j];
                }
            }
        }
    }
    int x1 = 0, x2 = 0, x3 = (1 << 10) - 1;
    for (int j = 0; j < maxn; j++){
        if (num[j] == 1){
            x3 ^= two[j];
        }
        if (num[j] == 2){
            x1 |= two[j];
        }
        else if (num[j] == 3){
            x2 |= two[j];
        }
    }
    printf("3\n");
    printf("| %d\n", x1);
    printf("^ %d\n", x2);
    printf("& %d", x3);
    return 0;
}