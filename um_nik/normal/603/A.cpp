#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int N = 100100;
int n;
char s[N];
int ans;

int main()
{
    scanf("%d %s", &n, &s);
    ans = 3;
    for (int i = 0; i < n - 1; i++)
        ans += (int)(s[i] != s[i + 1]);
    printf("%d\n", min(n, ans));

    return 0;
}