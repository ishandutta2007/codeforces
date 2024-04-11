#include <iostream>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    
    int n, m;
    while (t--) {
        scanf("%d%d", &n, &m);
        if (!(n & 1) || !(m & 1)) {
            printf("BB");
            for (int i = 2; i < m; ++i) {
                if (i & 1) printf("W");
                else printf("B");
            }
            printf("\n");
            for (int i = 1; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (!((i + j) & 1)) printf("B");
                    else printf("W");
                }
                printf("\n");
            }
        }
        else if (!(m & 1)) {
        }
        else {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (!((i + j) & 1)) printf("B");
                    else printf("W");
                }
                printf("\n");
            }
        }
    }
}