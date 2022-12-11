#include <bits/stdc++.h>
using namespace std;

int num[22];
int dat[22];

int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++) scanf("%d",&dat[i]);
    for (int i = 0; i < n; i++) num[i] = dat[i];
    sort(num, num + n);
    for (int i = 0; i < n; i++) dat[i] = lower_bound(num, num + n, dat[i]) - num;
    for (int i = 0; i < n; i++)
    {
        printf("%d ", num[(dat[i] + 1) % n]);
    }
    printf("\n");
}