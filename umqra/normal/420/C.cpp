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

const int N = (int)4e5 + 200;
                                                    
int f[N]; 
int cnt[N];
int n;
pii listA[N], listB[N];

void addVal(int x, int d)
{
    for (int i = x; i < N; i = (i | (i + 1)))
        f[i] += d;
}

int getVal(int x)
{
    int ans = 0;
    for (int i = x; i >= 0; i = ((i & (i + 1))) - 1)
        ans += f[i];         
    return ans;
}

int getCnt(int a, int b)
{
    return getVal(b) - (a == 0 ? 0 : getVal(a - 1));
}
                       
int changePair(pii *arr, int val, int d)
{
    int a, b;
    int l = -1, r = n;
    while (r - l > 1)
    {                                 
        int mid = (l + r) / 2;
        if (arr[mid].X >= val)
            r = mid;
        else
            l = mid;
    }
    a = r;
    l = -1, r = n;
    while (r - l > 1)
    {
        int mid = (l + r) / 2;
        if (arr[mid].X <= val)
            l = mid;
        else
            r = mid;
    }
    b = l;
    int len = 0;
    for (int i = a; i <= b; i++)
    {
        if (arr[i].X != val)
            break;
        len++;
        addVal(cnt[arr[i].X], -1);
        addVal(cnt[arr[i].Y], -1);       
        cnt[arr[i].X] += d;
        cnt[arr[i].Y] += d;
        addVal(cnt[arr[i].X], 1);
        addVal(cnt[arr[i].Y], 1);
    }
    return len;
}

int main()
{
#ifdef UMQRA
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif

    int p;
    scanf("%d%d", &n, &p);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        cnt[a]++;
        cnt[b]++;
        listA[i] = mp(min(a, b), max(a, b));
        listB[i] = mp(max(a, b), min(a, b));
    }
    for (int i = 1; i <= n; i++)
    {
        addVal(cnt[i], 1);     
    }
    sort(listA, listA + n);
    sort(listB, listB + n);
                                 

    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {                     
        int t = changePair(listA, i, -1) + changePair(listB, i, -1);
        
        ll q = getCnt(max(0, p - t), n) - (cnt[i] + t >= p ? 1 : 0);
        ans += q;
        changePair(listA, i, 1);
        changePair(listB, i, 1); 

    }
    cout << ans / 2;

    return 0;
}