#include "bits/stdc++.h"

using namespace std;

int main(int argc, char *argv[])
{
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    set<int> S;

    int suffix = n;
    while (suffix > 0 && S.count(a[suffix - 1]) == 0)
    {
        suffix--;
        S.insert(a[suffix]);
    }

    int max_s = S.size();

    for (int prefix = 0; prefix < n; ++prefix)
    {
        if (S.count(a[prefix]))
        {
            while (suffix < n && a[suffix] != a[prefix])
            {
                S.erase(a[suffix]);
                suffix++;
            }

            if (suffix == n)
                break;
            else
            {
                S.erase(a[suffix]);
                suffix++;
            }
        }

        S.insert(a[prefix]);
        max_s = max((int)S.size(), max_s);
    }

    cout << n - max_s << endl;

    return 0;
}