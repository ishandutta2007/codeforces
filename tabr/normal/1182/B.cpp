#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define forx(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, n) for (int i = 0; i < (n); i++)

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;
    h += 2;
    w += 2;
    vector<string> s(h);
    rep(i, h - 2)
    {
        string t;
        cin >> t;
        s[i + 1] = '.' + t + '.';
    }
    rep(i, w)
    {
        s[0].push_back('.');
        s[h - 1].push_back('.');
    }

    int p = 0, q = 0;
    forx(i, 1, h - 1) forx(j, 1, w - 1)
    {
        if (s[i][j] == '*' && s[i + 1][j] == '*' && s[i][j + 1] == '*' && s[i - 1][j] == '*' && s[i][j - 1] == '*')
        {
            p = i;
            q = j;
            s[p][q] = '.';
            break;
        }
    }

    if (p * q == 0)
    {
        cout << "NO" << endl;
        return 0;
    }

    int t = p;
    while (s[t + 1][q] == '*')
    {
        t++;
        s[t][q] = '.';
    }
    t = p;
    while (s[t - 1][q] == '*')
    {
        t--;
        s[t][q] = '.';
    }
    t = q;
    while (s[p][t + 1] == '*')
    {
        t++;
        s[p][t] = '.';
    }
    t = q;
    while (s[p][t - 1] == '*')
    {
        t--;
        s[p][t] = '.';
    }

    rep(i, h) rep(j, w) if (s[i][j] == '*')
    {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;

    return 0;
}