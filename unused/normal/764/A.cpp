#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    int n, m, k;
    scanf("%d%d%d",&n,&m,&k);
    printf("%d\n", k / (n * m / gcd(n, m)));
}