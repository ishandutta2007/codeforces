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

int dat[200005];
int t[200005], l[200005], r[200005];

int main()
{
    int n, q, m;
    scanf("%d%d%d",&n,&q,&m);
    for (int i = 1; i <= n; i++) scanf("%d",&dat[i]);

    for (int i = 0; i < q; i++)
    {
        scanf("%d%d%d",&t[i],&l[i],&r[i]);
    }

    for (int i = 0; i < m; i++)
    {
        int idx;
        scanf("%d",&idx);

        for (int j = q - 1; j >= 0; j--)
        {
            if (idx < l[j] || idx > r[j]) continue;

            if (t[j] == 1)
            {
                idx--;
                if (idx < l[j]) idx = r[j];
            }
            else
            {
                idx = r[j] - (idx - l[j]);
            }
        }

        printf("%d\n", dat[idx]);
    }
}