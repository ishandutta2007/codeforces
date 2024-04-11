#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string str;
    cin.sync_with_stdio(false);
    cin >> n >> str;
    int x = 0, y = 0, ans = 0;
    vector<int> vt{ 0 } ;
    for (char c : str)
    {
        if (c == 'U') ++x;
        else ++y;
        if (x == y) vt.push_back(0);
        else if (x > y) vt.push_back(1);
        else vt.push_back(-1);
    }

    for (int i = 1; i < vt.size() - 1; i++)
        if (vt[i - 1] * vt[i + 1] == -1) ++ans;
    cout << ans;
}