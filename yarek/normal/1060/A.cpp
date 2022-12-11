#include <bits/stdc++.h>
using namespace std;

char s[200];

int main()
{
    int n;
    scanf("%d %s", &n, s);
    int eight = count(s, s + n, '8');
    printf("%d\n", min(n / 11, eight));
}