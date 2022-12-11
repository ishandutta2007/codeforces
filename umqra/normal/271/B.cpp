#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <set>
#include <map>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define X first
#define Y second
#define mp make_pair

const int N = 510;

int prime[(int)1e6];
int table[N][N];
int t[N][N];
bool used[(int)1e6];
int ind = 0;

int myFind(int x)
{
    int l = -1, r = ind;
    while (r - l > 1)
    {
        int m = (l + r) / 2;
        if (prime[m] >= x)
            r = m;
        else
            l = m;
    }
    return r;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif
    
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int s = 0; s < m; s++)
            scanf("%d", &table[i][s]);

    for (int i = 2; i < (int)1e6; i++)
    {
        if (!used[i])
        {
            prime[ind++] = i;
            for (int s = i + i; s < (int)1e6; s += i)
                used[s] = 1;
        }
    }

    for (int i = 0; i < n; i++)
        for (int s = 0; s < m; s++)
        {
            int k = myFind(table[i][s]);
            t[i][s] = prime[k] - table[i][s];
        }

    int ans = (int)1e9;
    for (int i = 0; i < n; i++)
    {
        int locAns = 0;
        for (int s = 0; s < m; s++)
            locAns += t[i][s];
        ans = min(ans, locAns);
    }   
    for (int i = 0; i < m; i++)
    {
        int locAns = 0;
        for (int s = 0; s < n; s++)
            locAns += t[s][i];
        ans = min(ans, locAns);
    }   
    printf("%d", ans);


    return 0;
}