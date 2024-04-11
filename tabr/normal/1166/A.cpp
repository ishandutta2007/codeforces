#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define forx(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, n) for (int i = 0; i < (n); i++)

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, x = 0;
    cin >> n;
    vector<int> a(26);
    rep(i, n)
    {
        string s;
        cin >> s;
        a[s[0] - 'a']++;
    }
    rep(i, 26)
    {
        if (a[i] < 2)
            continue;
        int s = a[i] / 2;
        int t = a[i] - s;
        x += s * (s - 1) + t * (t - 1);
    }
    cout << x / 2 << endl;

    return 0;
}