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

string dat[105];

int main()
{
    int n;
    scanf("%d",&n);
    set<string> z;
    for (int i = 0; i < n; i++)
    {
        cin >> dat[i];
        if (z.insert(dat[i]).second) printf("NO\n");
        else printf("YES\n");
    }
}