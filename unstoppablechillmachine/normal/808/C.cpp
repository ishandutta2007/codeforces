#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const INF = 1e9 + 10;
ll const BINF = 1e18 + 10;
int const MAXN = 1e6 + 10;
ld const EPS = 1e-6;

#define f first
#define sec second
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mk make_pair
#define fro for
#define itn int
#define forn(i, n) for (int i = 1; i <= n; i++)
#define fore(i, n) for (int i = 0; i < n; i++)

int n, cnt, sum, now, ans[MAXN];
vector<pii> arr;

int main()
{
    //freopen("bacteria.in","r",stdin);
    //freopen("bacteria.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    cin >> n >> cnt;
    arr.resize(n + 1);
    forn(i, n)
    {
        cin >> arr[i].f;
        arr[i].sec = i;
    }
    forn(i, n)
    {
        ans[i] = arr[i].f / 2;
        if (arr[i].f % 2 == 1) ans[i]++;
        sum += ans[i];
    }

    if (sum > cnt)
    {
        cout << -1;
        exit(0);
    }
    sort(arr.begin(), arr.end());
    cnt -= sum;
    for(int i = n ; i >= 1;  i--)
    {
        //cout << arr[i].f << " " <<  << endl;
        if (!cnt) break;
        while (cnt && ans[arr[i].sec] < arr[i].f)
        {
            ans[arr[i].sec]++;
            cnt--;
        }
        //cout << arr[i].f << " " << ans[arr[i].sec] << endl;
    }

    if (cnt)
    {
        cout << -1;
        exit(0);
    }

    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
    {
        if (arr[j].sec == i) cout << ans[arr[j].sec] << " ";
    }











    return 0;
}