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

int arr[MAXN], n, m, l, r, x, a, sum;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    cin >> n >> m;
    forn(i, n)
    {
        cin >> arr[i];
    }

    forn(i, m)
    {
        cin >> l >> r >> x;
        if (x < l || x > r)
        {
            cout << "Yes" << endl;
            continue;
        }
        a = arr[x];
        sum = 0;
        for(int j = l; j <= r; j++)
        {
            if (arr[j] < a) sum++;
        }
        if (x == l + sum) cout << "Yes" << endl;
        else cout << "No" << endl;

    }








    return 0;
}