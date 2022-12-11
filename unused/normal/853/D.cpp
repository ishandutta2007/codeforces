#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <array>
#include <initializer_list>
#include <random>
#include <regex>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int a[300005];
int lastone[300005];
int nextone[300005];
long long sum[300005];
vector<int> vt[3];

int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&a[i]);
        sum[i] = sum[i - 1] + a[i];
        lastone[i] = (a[i] == 1000) ? i : lastone[i - 1];
    }
    for (int i = n; i >= 1; i--)
    {
        nextone[i] = (a[i] == 1000) ? i : nextone[i + 1];
    }

    long long ans = sum[n];

    for (int i = 1; i <= n; i++)
    {
        long long bonus = sum[i] / 10;
        long long rem = sum[n] - sum[i];
        long long res = sum[i] + rem - min(rem, bonus);
        ans = min(ans, res);

        if (a[i] == 2000)
        {
            int las = lastone[i];
            if (las)
            {
                res = sum[las - 1];
                bonus = sum[las - 1] / 10;
                res += a[las] - min(a[las] + 0ll, bonus);
                bonus -= min(a[las] + 0ll, bonus);
                bonus += (sum[i] - sum[las]) / 10;
                res += (sum[i] - sum[las]);
                rem = sum[n] - sum[i];
                res += rem - min(rem, bonus);
                ans = min(ans, res);
            }

            las = nextone[i + 1];
            if (las)
            {
                res = sum[i];
                bonus = sum[i] / 10;
                res += (sum[las - 1] - sum[i]) - min(sum[las - 1] - sum[i], bonus);
                bonus -= min(sum[las - 1] - sum[i], bonus);
                bonus += a[las] / 10;
                res += a[las];
                rem = sum[n] - sum[las];
                res += rem - min(rem, bonus);
                ans = min(ans, res);
            }
        }
    }

    printf("%lld\n", ans);
}