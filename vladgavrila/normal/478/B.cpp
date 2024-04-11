#include <cstdio>
#include <iostream>

using namespace std;

int n, m;

long long suma(int n)
{
    return 1LL*n*(n-1)/2;
}

int main()
{
    scanf("%d%d", &n, &m);

    long long mn = suma(n/m+1) * (n%m) + suma(n/m) * (m-n%m);\
    long long mx = suma(n-m+1);

    cout<<mn<<" "<<mx<<"\n";

    return 0;
}