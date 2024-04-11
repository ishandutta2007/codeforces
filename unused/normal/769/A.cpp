#include <bits/stdc++.h>
using namespace std;

int z[55];

int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++) scanf("%d",&z[i]);
    sort(z,z+n);
    printf("%d\n", z[n/2]);
}