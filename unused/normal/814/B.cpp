#include <bits/stdc++.h>
using namespace std;

int a[1005], b[1005];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    for (int i = 1; i <= n; i ++) cin >> b[i];

    vector<int> dif;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != b[i]) dif.push_back(i);
    }

    if (dif.empty())
    {
        set<int> av;
        vector<int> vt;
        for (int i = 1; i <= n; i++) av.insert(i);
        for (int i = 1; i <= n; i++)
        {
            if (av.count(a[i])) av.erase(a[i]);
            else vt.push_back(i);
        }

        a[vt[0]] = *av.begin();
    }
    else if (dif.size() == 1)
    {
        set<int> av;
        for (int i = 1; i <= n; i++) av.insert(i);
        for (int i = 1; i <= n; i++)
        {
            if (i == dif[0]) continue;
            av.erase(a[i]);
        }
        a[dif[0]] = *av.begin();
    }
    else
    {
        set<int> av;
        for (int i = 1; i <= n; i++) av.insert(i);
        for (int i = 1; i <= n; i++)
        {
            if (i == dif[0] || i == dif[1]) continue;
            av.erase(a[i]);
        }
        if ((a[dif[0]] != *av.begin()) == (a[dif[1]] != *av.rbegin())) swap(dif[0], dif[1]);
        if ((b[dif[0]] != *av.begin()) == (b[dif[1]] != *av.rbegin())) swap(dif[0], dif[1]);
        a[dif[0]] = *av.begin();
        a[dif[1]] = *av.rbegin();
    }

    for (int i = 1; i <= n; i++) cout << a[i] << ' ';
    cout << '\n';
}