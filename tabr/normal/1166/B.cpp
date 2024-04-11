#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define forx(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, n) for (int i = 0; i < (n); i++)

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int k, n = 5, m = -1;
    cin >> k;
    vector<char> a = {'a', 'e', 'i', 'o', 'u'};

    if (k < 5 * n)
    {
        cout << m << endl;
        return 0;
    }

    while (k % n != 0)
        n++;

    if (k < 5 * n)
    {
        cout << m << endl;
        return 0;
    }
    m = k / n;
    string s;
    rep(i, n) rep(j, m)
    {
        s.push_back(a[(i + j) % 5]);
    }
    cout << s << endl;

    return 0;
}