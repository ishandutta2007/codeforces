#include <iostream>
#include <string>
using namespace std;

int a[30];
int m[30];

int main()
{
#ifndef ONLINE_JUDGE
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif
    int k;
    string str;
    cin >> k >> str;
    for (int i = 0; i < str.length(); i++)
        a[str[i] - 'a']++;

    if (str.length() % k )
    {
        puts("-1");
        return 0;
    }

    for (int i = 0; i < 30; i++)
    {
        if (a[i] % k)
        {
            puts("-1");
            return 0;
        }
        m[i] = a[i] / k;
    }

    while (1)
    {
        bool h = false;
        for (int i = 0; i < 30; i++)
        {
            if (a[i])
            {
                h = true;
                for (int s = 0; s < m[i]; s++)
                    cout << (char)('a' + i);
                a[i] -= m[i];
            }
        }
        if (!h)
            break;
    }

    return 0;

}