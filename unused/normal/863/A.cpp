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


int main()
{
    int x;
    scanf("%d",&x);

    string z = to_string(x);
    while (z.empty() == false && z.back() == '0') z.pop_back();
    for (int i = 0; i < z.size(); i++)
    {
        if (z[i] != z[z.size() - 1 - i])
        {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
}