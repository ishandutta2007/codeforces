#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

int main()
{
#ifdef UMQRA
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif

    int a, b;
    cin >> a >> b;
    int ans = 0;
    int cntOld = 0;
    for (int i = 0; i < a; i++)
    {
        ans++;
        cntOld++;
        if (cntOld == b)
        {
            ans++;
            cntOld = 1;
        }
    }
    cout << ans;
                                
    return 0;
}