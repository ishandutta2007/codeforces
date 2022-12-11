#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

const int N = (int)1e5 + 100;
const ll p1 = 1298617;
const ll p2 = 9495;
const ll mod = (ll)1e9 + 7;

int add(int a, int b)
{
    return (a + b >= mod ? a + b - mod : a + b);
}

int mult(int a, int b)
{
    ll c = (ll)a * (ll)b;
    return (int)(c % mod);
}

pii add(pii a, pii b)
{
    return mp(add(a.X, b.X), add(a.Y, b.Y));
}

pii mult(pii a, pii b)
{
    return mp(mult(a.X, b.X), mult(a.Y, b.Y));
}

ll a[N];

struct item
{
    ll hash;
    int end;
    item () {}
    item (ll a, int b) : hash(a), end(b) {}
    bool operator < (const item &a) const
    {
        if (hash != a.hash)
            return hash < a.hash;
        return end < a.end;
    }
};
bool cmp(const item &a, const item &b)
{
    if (a.hash != b.hash)
        return a.hash < b.hash;
    return a.end < b.end;
}

 item list[45][N];
int indList[45];

int myLower(int ind, const item &a)
{
    int l = -1, r = indList[ind];
    while (r - l > 1)
    {
        int m = (l + r) / 2;
        if (list[ind][m] < a)
            l = m;
        else
            r = m;
    }
    return r;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif

    ll ans = 0;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%I64d", &a[i]);      

    ll curXor = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        curXor ^= a[i];   
        ll curNum = 0;
        for (int cnt = 39; cnt >= 0; cnt--)
        {
            curNum |= (curXor & ((ll)1 << (ll)cnt));
            list[cnt][indList[cnt]++] = item(curNum, i);
        }
    }

    for (int i = 0; i < 45; i++)
    {
      
        list[i][indList[i]++] = item(0, n);
    }

    for (int i = 0; i < 45; i++)
        sort(list[i], list[i] + indList[i], cmp);





 curXor = 0;
    for (int i = 0; i < n; i++)
    {
        ll bestNum = 0;
        for (int cnt = 39; cnt >= 0; cnt--)
        {
            ll bit = ((ll)1 << (ll)cnt) ^ (curXor & ((ll)1 << (ll)cnt));
            bestNum |= (bit);                
            int ind = myLower(cnt, item(bestNum, i));
            if (ind == indList[cnt] || list[cnt][ind].hash != bestNum)
                bestNum ^= ((ll)1 << (ll)cnt);
            if (ans >= ((bestNum ^ curXor) | (((ll)1 << (ll)cnt) - 1)))
                break;
        }            
        ans = max(ans, curXor ^ bestNum);
        curXor ^= a[i];
    }                     
    cout << ans;
    return 0;
}