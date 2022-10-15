#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
using std::cerr;
using std::cin;
using std::cout;
int t, n, q;
char s[101];
int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> t;
    while (t--)
    {
        cin >> n >> q >> s;
        while (q--)
        {
            int l, r, pos, lst = -1;
            bool f = true;
            cin >> l >> r;
            l--;
            r--;
            pos = l;
            for (int i = 0; i < n && pos <= r; i++)
            {
                if (s[i] == s[pos])
                {
                    pos++;
                    if (i != lst + 1 && lst != -1)
                    {
                        f = false;
                    }
                    lst = i;
                }
            }
            if (pos <= r)
            {
                cout << "NO\n";
                continue;
            }
            if (!f)
            {
                cout << "YES\n";
                continue;
            }
            for (int i = lst + 1; i < n; i++)
            {
                if (s[i] == s[r])
                {
                    f = false;
                    break;
                }
            }
            if (!f)
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
    }
    return 0;
}