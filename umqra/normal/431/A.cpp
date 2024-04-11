#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <string>
using namespace std;

int a[100];

int main()
{
#ifdef UMQRA
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif

    int ans = 0;
    for (int i = 0; i < 4; i++)
        cin >> a[i];
    string str;
    cin >> str;
    for (int i = 0; i < (int)str.length(); i++) ans += a[str[i] - '1'];
    cout << ans;

    return 0;
}