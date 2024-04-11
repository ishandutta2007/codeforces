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

int s[105];
int d[105], e[105];

int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= n; i++) scanf("%d",&s[i]);
    d[0] = 0; e[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (s[i])
        {
            d[i] = d[i - 1];
            e[i] = max(e[i - 1] + 1, d[i - 1] + 1);
        }
        else
        {
            d[i] = d[i - 1] + 1;
            e[i] = e[i - 1];
        }
    }
    printf("%d\n", max(d[n], e[n]));
}