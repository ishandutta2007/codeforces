#include <bits/stdc++.h>
using namespace std;

int x[65536];

int main()
{
    char z[1111];
    scanf("%*d%s", z);
    for (int i = 1; z[i]; i++) x[(unsigned short &)z[i - 1]]++;
    int y = max_element(x, x + 65536) - x;
    printf("%s\n", &y);
}