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

int const INF = 1e9 + 7;
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
#define forn(i, n) for (int i = 0; i <= n; i++)
#define fore(i, n) for (int i = 0; i < n; i++)
#define chcpy(Vec) copy(Vec.begin(), Vec.end(),ostream_iterator<char>(cout))
#define intcpy(Vec) copy(Vec.begin(), Vec.end(),ostream_iterator<int>(cout, " "))

ll dp[MAXN], sum, n, a;
vector<ll> arr;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    cin >> n;
    if (n == 1) 
    {
        cout << 0;
        exit(0);
    }
    arr.resize(n);
    fore(i, n)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    dp[0] = 0;
    dp[1] = arr[1] - arr[0];
    sum = dp[1];
    a = 4;
    for(int i = 2; i < n; i++)
    {
        dp[i] = (dp[i - 1] * 2 + (arr[i] - arr[i - 1]) * (a - 1)) % INF;
        sum = (sum + dp[i]) % INF;
        a = (a * 2) % INF;
        //cout << dp[i] << endl;
    }

    cout << sum;



    return 0;
}