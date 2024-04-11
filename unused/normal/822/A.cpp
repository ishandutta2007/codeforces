#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    scanf("%d%d",&a,&b);
    long long ret = 1;
    for (int i = 1; i <= min(a, b); i++) ret *= i;
    printf("%lld", ret);
}