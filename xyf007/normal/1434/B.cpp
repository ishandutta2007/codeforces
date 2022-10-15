#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
struct node
{
    char op[10];
    int v;
} a[200001];
int n, ans[100001];
bool vis[100001];
vector<int> v;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    v.emplace_back(0);
    int cnt = 0, tot = 0;
    for (int i = 1; i <= 2 * n; i++)
    {
        cin >> a[i].op;
        if (a[i].op[0] == '+')
        {
            cnt++;
            v.emplace_back(++tot);
        }
        else
        {
            cin >> a[i].v;
            cnt--;
            if (cnt < 0)
            {
                cout << "NO";
                return 0;
            }
            if (a[i].v < ans[v.back()])
            {
                cout << "NO";
                return 0;
            }
            else
            {
                ans[v[v.size() - 2]] = max(ans[v[v.size() - 2]], a[i].v);
                ans[v.back()] = a[i].v;
                v.pop_back();
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        vis[ans[i]] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES\n";
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << ' ';
    }
    return 0;
}