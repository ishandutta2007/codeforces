#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
string s;
vector<int> v;
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (s[i] == '1')
        {
            v.push_back(i);
        }
        else
        {
            if (!v.empty())
            {
                v.pop_back();
            }
        }
    }
    for (int i = 0; i < (int)v.size(); i++)
    {
        if (s[v[i]] == '1')
        {
            s[v[i]] = '0';
        }
    }
    cout << s;
    return 0;
}