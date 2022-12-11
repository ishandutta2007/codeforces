#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

const int N = (int)1e5 + 100;
ll x;
int n, d;
int a[N];
int b[N];
int res[N];
int nxt[N], prv[N];
int pos[N];
int cntOne[N];
int nxtOne[N];
const int mod = (int)1e9 + 7;

int mult(int a, int b)
{
    ll c = (ll)a * b;
    return c % mod;
}

int myPow(int a, int k)
{
    if (k == 0)
        return 1;
    if (k & 1)
        return mult(a, myPow(a, k - 1));
    else
    {
        int t = myPow(a, k / 2);
        return mult(t, t);
    }
}

ll getNextX() 
{
    x = (x * 37 + 10007) % 1000000007;
//  cout << x << endl;
    return x;
}

void initAB() 
{
    int i;
    for(i = 0; i < n; i = i + 1)
    {
        a[i] = i + 1;
    }
    for(i = 0; i < n; i = i + 1)
    {
        swap(a[i], a[getNextX() % (i + 1)]);
    }
//     for (i = 0; i < n; i++)
//      cout << a[i] << ' ';
//  cout << endl;
    for(i = 0; i < n; i = i + 1)
    {
        if (i < d)
            b[i] = 1;
        else
            b[i] = 0;
    }
    for(i = 0; i < n; i = i + 1)
    {
        swap(b[i], b[getNextX() % (i + 1)]);
    }
}


int main()
{
    cin >> n >> d >> x;
    initAB();
    
    int fst = -1;
    int lst = -1;
    for (int i = 0; i < n; i++)
    {
        cntOne[i] = (i == 0 ? 0 : cntOne[i - 1]);
        if (b[i] == 1)
        {
            cntOne[i]++;
            if (fst == -1)
                fst = i;
            else
                nxtOne[lst] = i;
            lst = i;
        }
    }
    nxtOne[lst] = n;
    
    int mx = n;
    for (int i = 1; i <= n; i++)
    {
        pos[a[i]] = i;
        prv[i] = i - 1;
        nxt[i] = i + 1;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (cntOne[i] <= 2000)
        {
            for (int s = fst; s <= i; s = nxtOne[s])
                res[i] = max(res[i], a[i - s]);
        }
        else
        {
//          int cc = 0;
            for (int s = mx; s != 0; s = prv[s])
            {
//              cc++;
                int p = pos[s];
                if (b[i - p])
                {
                    res[i] = s;
                    break;
                }
            }
//          cerr << cc << endl;
        }
        if (a[i] == mx)
            mx = prv[mx];
        else
        {
            int v = a[i];
            nxt[prv[v]] = nxt[v];
            prv[nxt[v]] = prv[v];
        }
    }
    for (int i = 0; i < n; i++)
        printf("%d\n", res[i]);
    
    return 0;
}