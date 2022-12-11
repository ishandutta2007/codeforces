#include <cstdio>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <map>

using namespace std;

const int N = 2e5 + 2;

int n;
pair<int, int> fr[N];
map<pair<int, int>, int> cnt;

int ToInt(char *s)
{
    stringstream ss(s);
    int ret; ss >> ret;
    return ret;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        char s[50], *pch; scanf("%s", s);
        pch = strtok(s, "()+/");
        int idx = 0, a = 0, b = 0;
        while (pch != NULL)
        {
            ++idx;
            if (idx == 3) b = ToInt(pch);
            else a += ToInt(pch);
            pch = strtok(NULL, "()+/");
        }
        int gcd = __gcd(a, b);
        a /= gcd, b /= gcd;
        fr[i] = {a, b};
        ++cnt[fr[i]];
    }
    for (int i = 0; i < n; ++i) printf("%d ", cnt[fr[i]]);
    return 0;
}