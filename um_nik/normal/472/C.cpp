#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;

int n;
string s, p, lst;
string a[100100][2], b[100100][2];

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> b[i][0] >> b[i][1];

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        x--;
        a[i][0] = b[x][0];
        a[i][1] = b[x][1];
    }
    lst = "";
    for (int i = 0; i < n; i++)
    {
        s = a[i][0];
        p = a[i][1];
        if (s > p)
            swap(s, p);
        if (lst > p)
        {
            printf("NO\n");
            return 0;
        }
        if (lst < s)
            lst = s;
        else
            lst = p;
    }
    printf("YES\n");

    return 0;
}