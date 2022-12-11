#include <bits/stdc++.h>
using namespace std;

string str;

string lst[] =
{
    "AA",
    "bd",
    "HH",
    "II",
    "MM",
    "OO",
    "oo",
    "pq",
    "TT",
    "UU",
    "VV",
    "vv",
    "WW",
    "ww",
    "XX",
    "xx",
    "YY"
};

bool z[256][256];

bool check(char a, char b)
{
    return z[a][b];
}

int main()
{
    for (auto &y : lst)
    {
        z[y[0]][y[1]] = true;
        z[y[1]][y[0]] = true;
    }

    cin >> str;

    for (int i = 0; i < str.size(); i++)
    {
        if (check(str[i], str[str.size() - 1 - i])==false)
        {
            printf("NIE\n");
            return 0;
        }
    }
    printf("TAK\n");
}