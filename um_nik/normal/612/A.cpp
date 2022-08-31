#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;

const int N = 111;
int n, p, q;
string s;

int main()
{
    cin >> n >> p >> q;
    cin >> s;
    for (int x = 0; x <= n; x++)
        for (int y = 0; y <= n; y++)
        {
            if (x * p + y * q != n) continue;
            cout << x + y << endl;
            int it = 0;
            for (int i = 0; i < x; i++)
            {
                cout << s.substr(it, p) << endl;
                it += p;
            }
            for (int i = 0; i < y; i++)
            {
                cout << s.substr(it, q) << endl;
                it += q;
            }
            return 0;
        }
    cout << "-1\n";

    return 0;
}