#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
int n;
string s;
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> s;
    for (char i = 'z'; i >= 'b'; i--)
    {
        for (int j = 0; j < (int)s.size();)
        {
            if (s[j] == i)
            {
                if (j && s[j - 1] == i - 1)
                {
                    s.erase(j, 1);
                }
                else
                {
                    if (j < (int)s.size() - 1 && s[j + 1] == i - 1)
                    {
                        s.erase(j, 1);
                        j--;
                    }
                    else
                    {
                        j++;
                    }
                }
            }
            else
            {
                j++;
            }
        }
    }
    cout << n - (int)s.size();
    return 0;
}