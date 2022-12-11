#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <cmath>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

const int N = (int)1e5 + 100;

ll delta[N];
ll val[N];
ll cost[N];
vector <int> g[N];
bool used[N];
ll allSum = 0;

ll gcd(ll a, ll b)
{
    return (b == 0 ? a : gcd(b, a % b));
}

bool isBig(ll a, ll b)
{                          
    if ((double)a * (double)b > 2e18)
        return true;
    return false;
}

ll getNok(ll a, ll b)
{
    ll d = gcd(a, b);
    a /= d;
    if (isBig(a, b))
    {
        return -1;
    }
    return a * b;
}

void fail()
{                         
    cout << allSum;
    exit(0);
}

void dfs(int v)
{
    used[v] = 1;
    bool child = false;
    ll curN = 1;                          
    ll minVal = (ll)2e18 + 100;
    ll cntC = 0;
    for (int i = 0; i < (int)g[v].size(); i++)
    {
        int to = g[v][i];
        if (!used[to])
        {   
            cntC++;
            child = true;
            dfs(to);
            minVal = min(minVal, val[to]);
            curN = getNok(curN, delta[to]);
            if (curN == -1)
                fail();
        }
    }
    if (!child)
    {
        val[v] = cost[v];
        delta[v] = 1;
    }
    else
    {
        ll k = minVal / curN;
        if (k == 0)
            fail();
        if (isBig(curN, cntC) || isBig(curN * cntC, k))
        {
            fail();
        }
        val[v] = curN * k * cntC;
        delta[v] = curN * cntC;
    }
}

int main()
{
#ifdef UMQRA
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%I64d", &cost[i + 1]);
        allSum += cost[i + 1];
    }

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1);
    cout << allSum - val[1];      

    return 0;
}