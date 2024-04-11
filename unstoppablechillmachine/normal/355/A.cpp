#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

#define _ inline
#define f first
#define sec second
#define pb push_back
#define ins insert
#define ers erase
#define mk make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rsz resize
#define int ll
#define forn(i, n) for (register int i(1); i <= n; i++)
#define fore(i, n) for (register int i(0); i < n; i++)
#define endl "\n"
#define right rightt
#define left leftt
#define prev prevv
#define next nextt

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 10;
const int P = 239017;
const long long BINF = 1e18 + 10;
const long double EPS = 1e-9;
const long double PI = acos(-1);

const int N = 9010;

int sum(int n)
{
    int res = 0;
    while (n) {
        res += n % 10;
        n /= 10;
    }
    return res;
}

string get(int cnt, int sum)
{
    int cur = 0;
    string ans;
    for (int i = 0; i < cnt; i++) {
        if (cur + 9 < sum) {
            ans += '9';
            cur += 9;
        }
        else {
            ans += char('0' + sum - cur);
            cur = sum;
        }
    }
    return ans;
}

_ void source()
{
    int n, k, dp[N];
    cin >> n >> k;
    if (n == 1 && !k) {
        cout << 0;
        exit(0);
    }
    int l = 1, r = n * 9;
    for (int i = 0; i < 10; i++) {
        dp[i] = i;
        if (i >= l && dp[i] == k) {
            cout << get(n, i);
            exit(0);
        }
    }
    for (int i = 10; i <= r; i++) {
        dp[i] = dp[sum(i)];
        if (i >= l && dp[i] == k) {
            cout << get(n, i);
            exit(0);
        }
    }
    cout << "No solution";
}

signed main()
{
#ifdef EXTRATERRESTRIAL_
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    //freopen(TASK".in", "r", stdin);
    //freopen(TASK".out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    source();
    return 0;
}