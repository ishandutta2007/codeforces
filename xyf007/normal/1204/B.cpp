#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
long long n, l, r;
int main(int argc, char const *argv[])
{
    scanf("%lld%lld%lld", &n, &l, &r);
    printf("%lld %lld", n - l + (1LL << l) - 1, (n - r) * (1LL << (r - 1)) + (1LL << r) - 1);
    return 0;
}