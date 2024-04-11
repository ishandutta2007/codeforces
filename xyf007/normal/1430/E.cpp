#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <fstream>
#include <cassert>
using namespace std;
int n, t[400005], last[101], nxt[200001], to[400001], pos[101];
bool vis[101];
string s;
void add(int x, int val)
{
    x++;
    while (x <= n + 1)
    {
        t[x] += val;
        x += x & -x;
    }
}
int query(int x)
{
    x++;
    int sum = 0;
    while (x)
    {
        sum += t[x];
        x -= x & -x;
    }
    return sum;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        if (vis[s[i] - 'a'])
        {
            nxt[last[s[i] - 'a']] = i;
        }
        else
        {
            pos[s[i] - 'a'] = i;
            vis[s[i] - 'a'] = 1;
        }
        last[s[i] - 'a'] = i;
        to[i] = s[n - i - 1] - 'a';
    }
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        int p = pos[to[i]] + query(pos[to[i]]);
        ans += p - i;
        add(0, 1);
        add(pos[to[i]], -1);
        pos[to[i]] = nxt[pos[to[i]]];
    }
    cout << ans;
    return 0;
}