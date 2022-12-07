#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;
int mod[4] = {4, 9, 6, 15};
int main(){
    int T, x;
    scanf("%d", &T);
    while (T--){
        scanf("%d", &x);
        int d = mod[x % 4];
        if (d != 15){
            if (d > x) printf("-1\n");
            else if (d == x) printf("1\n");
            else printf("%d\n", (x - d) / 4 + 1);
        }
        else{
            if (d > x) printf("-1\n");
            else if (d == x) printf("2\n");
            else printf("%d\n", (x - d) / 4 + 2);
        }
    }
    return 0;
}