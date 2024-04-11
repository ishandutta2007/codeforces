#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <string>
#include <cstring>
#include <complex>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
#define mp make_pair

const int N = 102;
const ll M = (ll)4e5;
int n;
ll a[N];
ll b[N];
ll k;
ll ans;

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d%lld", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%lld", &a[i]);

    ans = 1;
    
    for (ll d = 2; d <= M; d++) {
        ll kk = k;
        for (int i = 0; i < n; i++) {
            if (a[i] % d != 0)
                kk -= d - (a[i] % d);
        }
        if (kk >= 0) ans = d;
    }
    

    ll maxD = 0;
    for (int i = 0; i < n; i++)
        maxD += a[i];
    maxD += k;
    maxD /= n;
    bool maxIsOk = true;
    for (int i = 0; i < n; i++)
        maxIsOk &= (a[i] <= maxD);
    if (maxIsOk) {
        printf("%lld\n", maxD);
        return 0;
    }

    ll curD = M;
    ll curK = 0;
    ll curSum = 0;

    set<pli> setik;
    for (int i = 0; i < n; i++) {
        b[i] = (a[i] + curD - 1) / curD;
        curSum += b[i];
        ll m = b[i] * curD - a[i];
        curK += m;
        if (b[i] == 1) continue;
        setik.insert(mp(curD + (curD - m + b[i] - 2) / (b[i] - 1), i));
    }

    while(curD < maxD && !setik.empty()) {
        if (curK <= k)
            ans = max(ans, curD + (k - curK) / curSum);
        pli cur = *setik.begin();
        setik.erase(setik.begin());
        ll nxtD = cur.first;
        curK += (nxtD - curD) * curSum;
        int id = cur.second;
        curD = nxtD;
        curK -= b[id] * curD - a[id];
        curSum -= b[id];
        b[id] = (a[id] + curD - 1) / curD;
        ll m = b[id] * curD - a[id];
        curK += m;
        curSum += b[id];
        if (b[id] == 1) continue;
        setik.insert(mp(curD + (curD - m + b[id] - 2) / (b[id] - 1), id));
    }

    printf("%lld\n", ans);

    return 0;
}