#include "bits/stdc++.h"

using namespace std;

typedef unsigned long long ull;


vector<ull> a;
vector<ull> b;

bool compare(const int& i, const int& j)
{
    return a[i] < a[j];
}

int main(int argc, char *argv[])
{
    int n; cin >> n;

    a.assign(n, 0);
    b.assign(n, 0);

    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];

    vector<int> order(n);
    for (int i = 0; i < n; ++i)
    {
        order[i] = i;
    }
    sort(order.begin(), order.end(), compare);

    ull max_count = 0;
    vector<ull> known;
    vector<bool> visited(n, false);

    for (int i = 0; i + 1< n; ++i)
    {
        if (a[order[i]] == a[order[i+1]])
        {
            known.push_back(a[order[i]]);
            max_count += b[order[i]];
            visited[i] = true;

            while (i + 1 < n && a[order[i]] == a[order[i+1]])
            {
                i++;
                max_count += b[order[i]];
                visited[i] = true;
            }
        }
    }

    if (max_count == 0)
    {
        cout << 0 << endl;

        return 0;
    }

    for (int i = 0; i < n; ++i)
    {
        for (auto x : known)
        {
            if ((x | a[order[i]]) == x && visited[i] == false)
            {
                max_count += b[order[i]];
                break;
            }
        }
    }
    cout << max_count << endl;

    return 0;
}