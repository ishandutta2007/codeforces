#pragma GCC target("arch=ivybridge")
#include <cctype>
#include <cassert>
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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
using namespace std;

int bit[10];

int main()
{
    int n;
    scanf("%d",&n);
    for (int j = 0; j < 10; j++) bit[j] = 1;
    for (int i = 0; i < n; i++)
    {
        char ch; int x;
        scanf(" %c%d",&ch,&x);
        if (ch == '^')
        {
            for (int j = 0; j < 10; j++)
            {
                if (x & (1 << j))
                {
                    if (bit[j] <= 2) bit[j] ^= 3;
                    else bit[j] = 7 - bit[j];
                }
            }
        }
        else if (ch == '|')
        {
            for (int j = 0; j < 10; j++)
                if (x & (1 << j))
                    bit[j] = 3;
        }
        else
        {
            for (int j = 0; j < 10; j++)
                if (!(x & (1 << j))) bit[j] = 4;
        }
    }

    int XOR = 0, OR = 0;
    for (int i = 0; i < 10; i++)
    {
        if (bit[i] == 2) XOR += 1 << i;
        else if (bit[i] == 3) OR += 1 << i;
        else if (bit[i] == 4) XOR += 1 << i, OR += 1 << i;
    }

    // XOR - OR - AND

    printf("%d\n", !!XOR + !!OR);

    if (OR) printf("| %d\n", OR);
    if (XOR) printf("^ %d\n", XOR);
}