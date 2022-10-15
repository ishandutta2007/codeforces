#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstring>
#include <numeric>
size_t n, m, l[200001], r[200001], pos[26];
char s[200001], t[200001];
int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> (s + 1) >> (t + 1);
    n = std::strlen(s + 1);
    m = std::strlen(t + 1);
    std::fill(l, l + n + 1, 0);
    std::fill(r, r + n + 1, m + 1);
    size_t p = 1;
    for (size_t i = 1; i <= n; i++)
    {
        if (p <= m && s[i] == t[p])
        {
            l[i] = pos[s[i] - 'a'] = p++;
        }
        else
        {
            l[i] = pos[s[i] - 'a'];
        }
    }
    p = m;
    std::fill(pos, pos + 26, m + 1);
    for (size_t i = n; i >= 1; i--)
    {
        if (p && s[i] == t[p])
        {
            r[i] = pos[s[i] - 'a'] = p--;
        }
        else
        {
            r[i] = pos[s[i] - 'a'];
        }
    }
    for (size_t i = 1; i <= n; i++)
    {
        if (l[i] < r[i])
        {
            std::cout << "No";
            return 0;
        }
    }
    std::cout << "Yes";
    return 0;
}