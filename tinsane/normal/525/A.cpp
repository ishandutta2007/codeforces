#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <map>
#include <cmath>
#include <string>
#include <stack>
#include <set>
#include <algorithm>
#include <list>
using namespace std;
//8739
const double PI = 3.14159265358979323846;
const long long MODUL = 1000000007;
const long long MAXINT = 1000000010;
const long long MAXLL = 1000000000000000000;

template <typename T>
inline T MIN(T lef, T ri)
{
    return (lef < ri ? lef : ri);
}

template <typename T>
inline T MAX(T lef, T ri)
{
    return (lef > ri ? lef : ri);
}

template <typename T>
inline T MOD(T val)
{
    return (val > 0 ? val : -val);
}

#pragma comment(linker, "/STACK:1677721600")

int main()
{
    ios_base::sync_with_stdio(0);
    int n, cnt[256], ans(0);
    string s;
    cin >> n >> s;
    --n;
    memset(cnt, 0, 256 * sizeof(int));
    for(int i(0); i < n * 2; i += 2)
    {
        ++cnt[s[i] + ('A' - 'a')];
        if(cnt[s[i + 1]])
            --cnt[s[i + 1]];
        else
            ++ans;
    }
    cout << ans;
    return 0;
}