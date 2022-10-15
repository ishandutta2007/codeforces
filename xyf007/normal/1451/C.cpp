#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
using std::cin;
using std::cout;
using std::cerr;
int t, n, k, cnta[26], can[26], cntb[26];
char a[1000001], b[1000001];
int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> t;
    while (t--)
    {
        memset(cnta, 0, sizeof(cnta));
        memset(cntb, 0, sizeof(cntb));
        memset(can, 0, sizeof(can));
        cin >> n >> k >> a >> b;
        for (int i = 0; i < n; i++)
        {
            cnta[a[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++)
        {
            can[i] = cnta[i] / k * k;
            cnta[i] %= k;
        }
        for (int i = 0; i < n; i++)
        {
            cntb[b[i] - 'a']++;
        }
        bool f = true;
        for (int i = 0; i < 26; i++)
        {
            if (cnta[i] > cntb[i])
            {
                cout << "No\n";
                f = false;
                break;
            }
            cntb[i] -= cnta[i];
        }
        if (!f)
        {
            continue;
        }
        int sum = 0;
        for (int i = 0; i < 26; i++)
        {
            sum += can[i];
            if (sum < cntb[i] || (sum - cntb[i]) % k)
            {
                cout << "No\n";
                f = false;
                break;
            }
            sum -= cntb[i];
        }
        if (f)
        {
            cout << "Yes\n";
        }
    }
    return 0;
}