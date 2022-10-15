#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
int t;
string a, b;
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int i = 0;
        while (b[i] != '1')
        {
            i++;
        }
        for (int j = i; j < (int)a.size(); j++)
        {
            if (a[j] == '1')
            {
                cout << j - i << endl;
                break;
            }
        }
    }
    return 0;
}