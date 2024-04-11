/*














*/
/*
  !










*/
/*

















*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const INF = 1e9;
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
#define forn(i, n) for (int i(1); i <= n; i++)
#define fore(i, n) for (int i(0); i < n; i++)
#define chcpy(Vec) copy(Vec.begin(), Vec.end(),ostream_iterator<char>(cout))
#define intcpy(Vec) copy(Vec.begin(), Vec.end(),ostream_iterator<int>(cout, " "))

ll n, m, k, t, s, s1, x, min1 = 2 * INF, ans = 2 * INF, j, sum;
vector<pll> arr, arr2;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    cin >> k >> m >> n;
    cin >> x >> s;
    arr.resize(m);
    arr2.resize(n);
    fore(i, m) cin >> arr[i].sec;
    fore(i, m) cin >> arr[i].f;
    sort(arr.begin(), arr.end());
    fore(i, n) cin >> arr2[i].sec;
    fore(i, n) cin >> arr2[i].f;
    ans = k * x;
    //cout << ans << endl;
    for(int i = n - 1; i >= 0; i--)
    {
        if (s < arr2[i].f) continue;
        ans = min(ans, (k - arr2[i].sec) * x);
        sum = k * x;
        s1 = s - arr2[i].f;
        while(j < m && arr[j].f <= s1)
        {
            min1 = min(min1, arr[j].sec);
            j++;
        }
        ans = min(ans, (k - arr2[i].sec) * min1);
        //cout << sum << " " << " " << arr2[i].sec << " " << min1 << " " << j << " " << ans << endl;
        //cout << sum - arr2[i].sec * x - (x - min1) << endl;
    }
    fore(i, m)
    {
        if (arr[i].f <= s) ans = min(ans, k * arr[i].sec);
    }

    cout << ans;

    return 0;
}