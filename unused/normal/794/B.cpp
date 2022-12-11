#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, h;
    cin >> n >> h;

    for (int i = 1; i < n; i++)
    {
        printf("%.9f ", sqrt(i) / sqrt(n) * h);
    }
    printf("\n");
}