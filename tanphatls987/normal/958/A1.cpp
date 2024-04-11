#include <cstdio>
#include <algorithm>

using namespace std;

int n;
char a[12][12], b[12][12], c[12][12];

bool Match()
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (a[i][j] != b[i][j]) return false;
    return true;
}

void Rotate()
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            c[j][n - i - 1] = a[i][j];

    for (int i = 0; i < n; ++i)
        copy(c[i], c[i] + n, a[i]);
}

void Flip()
{
    for (int i = 0; i < n / 2; ++i)
        for (int j = 0; j < n; ++j)
            swap(a[i][j], a[n - i - 1][j]);
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%s", a[i]);
    for (int i = 0; i < n; ++i) scanf("%s", b[i]);
    for (int k = 0; k < 8; ++k)
    {
        if (Match())
        {
            printf("Yes");
            return 0;
        }
        Rotate();
        if (k == 3) Flip();
//        printf("Step %d: \n", k);
//        for (int i = 0; i < n; ++i) printf("%s\n", a[i]);
    }
    printf("No");
    return 0;
}