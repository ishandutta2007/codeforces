#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    int p1 = max(3*a/10, a-a/250*c);
    int p2 = max(3*b/10, b-b/250*d);
    if (p1 > p2) printf("Misha");
    else if (p1 < p2) printf("Vasya");
    else printf("Tie");
}