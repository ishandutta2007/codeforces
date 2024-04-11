#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
string s;
int main(int argc, char const *argv[])
{
    cin >> s;
    int sz = (int)s.size();
    if (sz & 1)
    {
        bool f = 0;
        for (int i = 1; i < sz; i++)
        {
            if (s[i] == '1')
            {
                f = 1;
            }
        }
        if (f)
        {
            printf("%d", sz / 2 + 1);
        }
        else
        {
            printf("%d", sz / 2);
        }
    }
    else
    {
        printf("%d", sz / 2);
    }
    return 0;
}