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

int n, a[MAXN];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    cin >> n;
    forn(i, n)
    {
        cin >> a[i];
        if (!a[i]) continue;
        a[i] %= 2;
        if (!a[i]) a[i] += 2;
    }
    forn(i, n - 1)
    {
        if (a[i] > 2 || a[i] < 0)
        {
            cout << "NO";
            exit(0);
        }
        if (!a[i]) continue;
        if (a[i] == 2) a[i] = 0;
        else
        {
            a[i]--;
            a[i + 1]--;
        }
    }

    if (!a[n] || a[n] == 2) cout << "YES";
    else cout << "NO";

    return 0;
}