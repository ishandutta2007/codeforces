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

const int INF = (int)1e9 + 10;
const int N = (int)1e5 + 100;
vector <int> listPos[N];
vector <int> listVal[N];
int a[N], b[N];
int dp[N];
int prevMin[N];


int main()
{
#ifdef UMQRA
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif

    int n, m, s, e;
    scanf("%d%d%d%d", &n, &m, &s, &e);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        listVal[a[i]].push_back(i);
    }

    for (int i = 0; i < m; i++)
    {
        scanf("%d", &b[i]);
        listPos[b[i]].push_back(i);
    }

    for (int i = 0; i < N; i++)
        prevMin[i] = INF;
    
    int ans = 0;
    for (int mv = 1; mv <= s / e; mv++)
    {
        for (int val = 1; val <= N; val++)
        {
            int it = (int)listPos[val].size() - 1;
            for (int i = 0; i < (int)listVal[val].size(); i++)
            {
                int pos = listVal[val][i];
                int x = (pos == 0 ? INF : prevMin[pos - 1]);
                if (mv == 1)
                    x = -1;
                while (it > 0 && listPos[val][it - 1] > x)
                    it--;
                if (it >= 0 && listPos[val][it] > x)
                {
                    dp[pos] = listPos[val][it];
                    if (pos + 1 + listPos[val][it] + 1 <= s - e * mv)
                        ans = max(ans, mv);
                }
                else
                    dp[pos] = INF;
            }
        }
        prevMin[0] = dp[0];
        for (int pos = 1; pos < n; pos++)
            prevMin[pos] = min(prevMin[pos - 1], dp[pos]); 
    }   
    cout << ans;

    return 0;
}