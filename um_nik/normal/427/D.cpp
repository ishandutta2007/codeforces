#include <iostream>
#include <string>
using namespace std;

const int INF = (int)1e7;
string t1, t2;
string s;
int n, m;
int z[21000];
int ans = INF;

void calc()
{
    for (int i = 0; i < n; i++)
        z[i] = 0;
    int l = 0;
    int r = 0;
    for (int i = 1; i < n; i++)
    {
        if (i <= r)
            z[i] = min(z[i - l], r - i);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
                z[i]++;
        if (i + z[i] > r)
        {
            l = i;
            r = i + z[i];
        }
    }
    return;
}

int main()
{
    cin >> t1;
    cin >> t2;
    m = t1.length();
    for (int i = 0; i < m; i++)
    {
        s = t1.substr(i, m - i) + '#' + t1 + '%' + t2;
        n = s.length();
        calc();
        z[m + 1] = 0;
        int tmp = 0;
        int tmp2 = 0;
        bool good = false;
        int idx = -1;
        for (int i = 1; i < n; i++)
        {
            if (z[i] > tmp)
            {
                tmp2 = tmp;
                tmp = z[i];
                idx = i;
                good = 1;
            }
            else if (z[i] == tmp)
                good = 0;
            else if (z[i] > tmp2)
                tmp2 = z[i];
        }
        if (good && idx > 2 * m - i + 1)
            ans = min(ans, tmp2 + 1);
    }
    if (ans == INF)
        printf("-1\n");
    else
        printf("%d\n", ans);
//  cin >> n;
    return 0;
}