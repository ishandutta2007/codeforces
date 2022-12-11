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

int dat[100005][4];
int cnt[16];

int main()
{
    int n, k;
    scanf("%d%d",&n,&k);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            scanf("%d",&dat[i][j]);
        }
        int z = 0;
        for (int j = 0; j < k; j++)
        {
            z |= dat[i][j] << j;
        }
        cnt[z]++;
    }

    if (cnt[0])
    {
        printf("YES\n");
        return 0;
    }

    for (int i = 0; i < 16; i++)
    {
        if (cnt[i] == 0) continue;
        for (int j = i + 1; j < 16; j++)
        {
            if (i & j) continue;
            if (cnt[i] && cnt[j])
            {
                printf("YES\n");
                return 0;
            }
        }
    }
    printf("NO\n");
}