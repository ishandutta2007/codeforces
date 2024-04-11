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

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int x, y[4];
        scanf("%d",&x);
        for (int i = 1; i <= 3; i++) scanf("%d",&y[i]);
        bool visit[4] = {};
        do
        {
            visit[x] = true;
            x = y[x];
        } while (x && !visit[x]);

        if (visit[1] && visit[2] && visit[3]) printf("YES\n");
        else printf("NO\n");
    }
}