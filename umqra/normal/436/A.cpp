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
#include <ctime>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

const int N = (int)3e3;
int h[N], m[N], t[N];
int used[N];
int ans = 0;
int n;

void solve(int ind, int jmp, int cnt)
{
    int pos = -1, bst = 0;
    for (int i = 0; i < n; i++)
    {
        if (!used[i] && t[i] == ind && h[i] <= jmp && m[i] > bst)
        {
            bst = m[i];
            pos = i;
        }
    }
    if (pos == -1)
        return;
    ans = max(ans, cnt);
    used[pos] = 1;
    solve(!ind, jmp + bst, cnt + 1);
}

int main()
{
    int x;
    scanf("%d%d", &n, &x);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d", &t[i], &h[i], &m[i]);
    }
    
    solve(0, x, 1);
    memset(used, 0, sizeof(used));
    solve(1, x, 1);
    cout << ans;
    
    return 0;
}