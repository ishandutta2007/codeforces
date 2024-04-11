#include <cstdio>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <numeric>
#include <functional>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <memory>
#include <thread>
#include <tuple>
#include <random>
#include <limits>
#include <chrono>
#include <ctime>
#include <bitset>
#include <list>
#include <stack>
using namespace std;

char buf[200005];

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s", buf);

        int len = strlen(buf);
        int l = 0, r = 0;

        for (int i = 0; i < len; i++)
        {
            if (buf[i] == '(') ++l;
            else if (buf[i] == ')') ++r;
        }

        vector<char> vt;
        for (int i = 0; i < len / 2 - l; i++) vt.push_back('(');
        for (int i = 0; i < len / 2 - r; i++) vt.push_back(')');
        if (!next_permutation(vt.begin(), vt.end()))
        {
            printf("YES\n");
            continue;
        }

        bool wrong = false;
        int cnt = 0;
        for (int i = 0, j = 0; i < len; i++)
        {
            char f = buf[i] == '?' ? vt[j++] : buf[i];
            if (f == '(') ++cnt;
            else if (--cnt < 0)
            {
                wrong = true;
                break;
            }
        }
        if (wrong) printf("YES\n");
        else printf("NO\n");
    }
}