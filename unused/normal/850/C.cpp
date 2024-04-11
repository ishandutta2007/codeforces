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

int a[105];
set<int> primes;
map<set<int>, int> grundy;

int getgrundy(set<int> &st)
{
    if (st.empty()) return 0;

    auto ret = grundy.emplace(st, 0);
    auto &r = ret.first->second;
    if (ret.second)
    {
        set<int> nxt;
        for (int i = 1; i <= *st.rbegin(); i++)
        {
            set<int> tries;
            for (int j : st)
            {
                if (j < i) tries.insert(j);
                else if (j > i) tries.insert(j - i);
            }

            nxt.insert(getgrundy(tries));
        }

        while (nxt.count(r)) ++r;
    }

    return r;
}

int main()
{
    int n;
    scanf("%d",&n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
        int X = a[i];
        for (int j = 2; j * j <= X; j++)
        {
            if (X % j == 0)
            {
                primes.insert(j);
                while (X % j == 0) X /= j;
            }
        }

        if (X > 1) primes.insert(X);
    }

    int grundy = 0;

    for (int p : primes)
    {
        set<int> st;
        for (int i = 0; i < n; i++)
        {
            int X = a[i];
            int cnt = 0;
            while (X % p == 0) X /= p, ++cnt;
            if (cnt) st.insert(cnt);
        }

        grundy ^= getgrundy(st);
    }

    if (grundy) printf("Mojtaba\n");
    else printf("Arpa\n");
}