#include <bits/stdc++.h>
using namespace std;

int a[101];
int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a+1, a+1+n);
    int g = a[1];
    for (int i = 2; i <= n; i++) g = gcd(g, a[i]);
    int last = a[n] / g;
    if ((last + n) % 2) printf("Alice\n");
    else printf("Bob\n");
}