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

const int N = (int)1e6;
int cnt[N];
int q[N];
bool bad[N];
int st[N];
int ans[N];
int ind = 0;

int main()
{
#ifdef UMQRA
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif

    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++)
    {
        char c;
        int t;
        scanf(" %c%d", &c, &t);
        if (c == '+')
            q[i] = t;
        else
            q[i] = -t;
    }                                                         
    
    int curCnt = 0;
    for (int i = 0; i < m; i++)
    {
        if (q[i] < 0)
        {
            if (st[-q[i]] == 0)
            {
                cnt[-q[i]] = 1;
                st[-q[i]] = 1;
                curCnt++;
            }
        }
        else
            st[q[i]] = 1;
    }
    
    for (int i = 0; i < m; i++)
    {
        if (q[i] < 0)
        {
            if (i != m - 1 && q[i] + q[i + 1] != 0)
                bad[-q[i]] = 1;
            if (curCnt > 1)
                bad[-q[i]] = 1;
            curCnt--;
            cnt[-q[i]] = 0;
        }
        else
        {
            if (i != 0 && q[i - 1] + q[i] != 0)
                bad[q[i]] = 1;
            if (curCnt > 0)
                bad[q[i]] = 1;
            curCnt++;
            cnt[q[i]] = 0;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (!bad[i])
            ans[ind++] = i;
    }
    printf("%d\n", ind);
    for (int i = 0; i < ind; i++)
        printf("%d ", ans[i]);

    return 0;
}