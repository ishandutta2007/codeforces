#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;

int n, m;
string a;
string b;

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    cin >> n >> m;
    cin >> a >> b;
    if (a[0] == '>' && a[n - 1] == '<' && b[0] == '^' && b[m - 1] == 'v')
    {
        printf("YES\n");
        return 0;
    }
    if (a[0] == '<' && a[n - 1] == '>' && b[0] == 'v' && b[m - 1] == '^')
    {
        printf("YES\n");
        return 0;
    }
    printf("NO\n");

    return 0;
}