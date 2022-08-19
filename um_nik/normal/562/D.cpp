#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <set>
#include <map>
#include <string>
#include <cstring>
using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second 
#define mp make_pair

const int N = (int)3e5 + 10;
const int LEN = 450;
int par[N];
int sz[N];
int go[N];
bool joined[N];

void init()
{
    for (int i = 0; i < N; i++)
        par[i] = i;
}

int get(int a)
{
    return par[a] = (par[a] == a ? a : get(par[a]));
}

void join(int a, int b)
{
    a = get(a);
    b = get(b);
    if (a == b)
        return;
    if (sz[a] == sz[b])
        sz[a]++;
    if (sz[a] > sz[b])
        par[b] = a;
    else
        par[a] = b;
}

void joinSegment(int a, int b)
{
    for (int i = a; i < b;)
    {
        if (i % LEN == 0)
        {
            int e = i + LEN;
            if (e <= b)
            {
                if (!joined[i])
                {
                    joined[i] = true;
                    for (int s = i; s < e; s++)
                        join(s, s + 1);
                }
                i = e;
                continue;
            }
        }
        join(i, i + 1);
        i++;
    }
}

int main()
{
#ifdef LOCAL
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif

    init();
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int type, a, b;
        scanf("%d%d%d", &type, &a, &b);
        eprintf("%d %d %d\n", type, a, b);
        a--, b--;
        if (type == 1)
            join(a, b);
        else if (type == 2)
        {
            joinSegment(a, b);
        }
        else
            printf("%s\n", get(a) == get(b) ? "YES" : "NO");
    }

    return 0;
}