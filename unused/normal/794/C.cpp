#include <bits/stdc++.h>
using namespace std;

string a, b;

int main()
{
    cin.sync_with_stdio(false);
    cin >> a >> b;
    int n = a.size();
    sort(a.begin(), a.end(), greater<>());
    a.erase(a.begin(), a.begin() + n / 2);
    sort(b.begin(), b.end());
    b.erase(b.begin(), b.begin() + (n + 1) / 2);

    string frn;
    deque<char> bck;

    int a1 = 0, a2 = a.size(), b1 = 0, b2 = b.size();

    for (int i = 0; i < n; i++)
    {
        if (!(i & 1))
        {
            if (b1 == b2 || a[a2 - 1] < b[b2 - 1])
            {
                frn.push_back(a[--a2]);
            }
            else
            {
                bck.push_front(a[a1++]);
            }
        }
        else
        {
            if (a1 == a2 || b[b2 - 1] > a[a2 - 1])
            {
                frn.push_back(b[--b2]);
            }
            else
            {
                bck.push_front(b[b1++]);
            }
        }
    }

    frn.insert(frn.end(), bck.begin(), bck.end());

    cout << frn << '\n';
}