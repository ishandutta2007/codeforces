#include <cstdio>
#include <algorithm>

using namespace std;

int n, m, a, b;

int main()
{
    scanf("%d%d%d%d", &n, &m, &a, &b);

    printf("%d\n", min((n/m)*b+(n%m)*a, min(n*a, (n/m+1)*b)));

    return 0;
}