#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <deque>
using namespace std;
int n, m;
string s[101];
deque<string> ans;
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }
    int id = -1, len = 0;
    for (int i = 1; i <= n; i++)
    {
        string tmp = s[i];
        reverse(tmp.begin(), tmp.end());
        if (tmp == s[i])
        {
            id = i;
            continue;
        }
        for (int j = i + 1; j <= n; j++)
        {
            if (s[j] == tmp)
            {
                ans.push_front(s[i]);
                ans.push_back(tmp);
                len += 2 * (int)s[i].size();
                break;
            }
        }
    }
    if (id)
    {
        cout << len + (int)s[id].size() << endl;
        for (int i = 0; i < (int)ans.size() / 2; i++)
        {
            cout << ans[i];
        }
        cout << s[id];
        for (int i = (int)ans.size() / 2; i < (int)ans.size(); i++)
        {
            cout << ans[i];
        }
    }
    else
    {
        cout << len << endl;
        for (int i = 0; i < (int)ans.size(); i++)
        {
            cout << ans[i];
        }
    }
    return 0;
}