#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        char t[101];
        scanf("%s", t);
        int n = strlen(t);
        int only = t[0] - '0';
        for (int i = 1; i < n; ++i) {
            if (t[i] - '0' != only) only = 3;
        }
        if (only < 3) for (int i = 0; i < n; ++i) printf("%d", only);
        else for (int i = 0; i < n; ++i) printf("01");
        printf("\n");
    }
    return 0;
}