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
#define forn(i, n) for (int i(1); i <= n; i++)
#define fore(i, n) for (int i(0); i < n; i++)
#define chcpy(Vec) copy(Vec.begin(), Vec.end(),ostream_iterator<char>(cout))
#define intcpy(Vec) copy(Vec.begin(), Vec.end(),ostream_iterator<int>(cout, " "))

ll n, sum, a[MAXN], s, l, r, mid;
vector<ll> Vec;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    cin >> n >> sum;
    forn(i, n)
    {
        cin >> a[i];
        //Vec.pb(a + i + 1);
    }
    l = 0;
    r = n + 1;
    while (r - l - 1)
    {
        mid = (r + l) / 2;
        Vec.clear();
        s = 0;
        forn(i, n) Vec.pb(a[i] + mid * i);
        sort(Vec.begin(), Vec.end());
        fore(i, mid) s += Vec[i];
        if (sum >= s) l = mid;
        else r = mid;
    }


    //cout << l;
    s = 0;
    Vec.clear();
    forn(i, n) Vec.pb(a[i] + l * i);
    sort(Vec.begin(), Vec.end());
    fore(i, l) s += Vec[i];
    cout << l << " " << s;

    return 0;
}