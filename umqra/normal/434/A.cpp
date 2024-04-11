#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

const int N = (int)1e5 + 100;
vector <int> listV[N];
int a[N];

int main()
{
#ifdef UMQRA
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif

    int n, m;
    scanf("%d%d", &n, &m);  

    for (int i = 0; i < m; i++)
        scanf("%d", &a[i]);

    for (int i = 0; i < m; i++)
    {
        if (i != 0 && a[i - 1] != a[i])
            listV[a[i]].push_back(a[i - 1]);
        if (i != m - 1 && a[i + 1] != a[i])
            listV[a[i]].push_back(a[i + 1]);
    }
                  
    ll res = 0;
    for (int i = 0; i < m - 1; i++)
        res += abs(a[i] - a[i + 1]);
    ll ans = res;
    for (int i = 1; i <= n; i++)
    {
        if (listV[i].size() == 0)
            continue;               
        sort(listV[i].begin(), listV[i].end());
        ll curVal = 0;
        ll bstVal = 0;
        for (int s = 0; s < (int)listV[i].size(); s++)
            curVal += abs(listV[i][s] - i);
        int bst = listV[i][(int)listV[i].size() / 2];
        for (int s = 0; s < (int)listV[i].size(); s++)
            bstVal += abs(listV[i][s] - bst);
        ans = min(ans, res - curVal + bstVal);
    }
    cout << ans;

    return 0;
}