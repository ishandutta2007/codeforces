#include <bits/stdc++.h>
using namespace std;

const int N = 100;
int a[N];

int main()
{
    int n;
    scanf("%d", &n);
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        scanf("%d", a + i);
        sum += a[i];
    }
    printf("%d\n", max(2 * sum / n + 1, *max_element(a, a + n)));
}