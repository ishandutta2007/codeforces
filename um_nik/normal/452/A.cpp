#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;

string s;
int n;
string a[10];

void init()
{
//  Vaporeon, Jolteon, Flareon, Espeon, Umbreon, Leafeon, Glaceon  Sylveon
    a[0] = "vaporeon";
    a[1] = "jolteon";
    a[2] = "flareon";
    a[3] = "espeon";
    a[4] = "umbreon";
    a[5] = "leafeon";
    a[6] = "glaceon";
    a[7] = "sylveon";
}

int main()
{
    init();
    cin >> n >> s;
    for (int i = 0; i < 8; i++)
    {
        if (n != a[i].length())
            continue;
        bool g = 1;
        for (int j = 0; j < n; j++)
            if (!(s[j] == '.' || s[j] == a[i][j]))
                g = 0;
        if (g)
        {
            cout << a[i] << endl;
            return 0;
        }
    }

    return 0;
}