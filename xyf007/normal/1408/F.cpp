#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int n;
vector<pair<int, int>> ans;
void solve(int l, int len)
{
    for (int i = 1; (i << 1) <= len; i <<= 1)
    {
        for (int j = l; j <= l + len - 1; j += (i << 1))
        {
            for (int k = 0; k < i; k++)
            {
                ans.emplace_back(make_pair(j + k, j + k + i));
            }
        }
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int len = 1;
    while ((len << 1) <= n)
    {
        len <<= 1;
    }
    solve(1, len);
    solve(n - len + 1, len);
    cout << ans.size() << '\n';
    for (auto &&i : ans)
    {
        cout << i.first << ' ' << i.second << '\n';
    }
    return 0;
}