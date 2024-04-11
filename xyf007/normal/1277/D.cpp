#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
using namespace std;
int t, n;
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<string> s(n);
        vector<bool> u(2);
        set<string> s01, s10;
        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
            if (s[i][0] == '0' && s[i].back() == '1')
            {
                s01.insert(s[i]);
            }
            if (s[i][0] == '1' && s[i].back() == '0')
            {
                s10.insert(s[i]);
            }
            u[s[i][0] - '0'] = u[s[i].back() - '0'] = 1;
        }
        if (u[0] && u[1] && s01.empty() && s10.empty())
        {
            cout << -1 << endl;
            continue;
        }
        vector<int> rev;
        if ((int)s01.size() > (int)s10.size() + 1)
        {
            for (int i = 0; i < n; i++)
            {
                if (s[i][0] == '0' && s[i].back() == '1')
                {
                    string ss(s[i]);
                    reverse(ss.begin(), ss.end());
                    if (!s10.count(ss))
                    {
                        rev.push_back(i);
                    }
                }
            }
        }
        else
        {
            if ((int)s10.size() > (int)s01.size() + 1)
            {
                for (int i = 0; i < n; i++)
                {
                    if (s[i][0] == '1' && s[i].back() == '0')
                    {
                        string ss(s[i]);
                        reverse(ss.begin(), ss.end());
                        if (!s01.count(ss))
                        {
                            rev.push_back(i);
                        }
                    }
                }
            }
        }
        int ans = max(0, (int(max((int)s01.size(), (int)s10.size())) - int(min((int)s01.size(), (int)s10.size()))) / 2);
        cout << ans << endl;
        for (int i = 0; i < ans; i++)
        {
            cout << rev[i] + 1 << " ";
        }
        cout << endl;
    }
    return 0;
}