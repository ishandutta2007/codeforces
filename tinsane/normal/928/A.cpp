#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define dbg(...) fprintf(stderr, __VA_ARGS__)
#define dbgv(x) cerr << #x << " = " << x << endl
#define dbga(arr, len) {cerr << #arr << " = "; for (int _ = 0; _ < len; _++) cerr << arr[_] << " "; cerr << endl;}
#define dbgi(it) {cerr << #it << " = "; for (const auto &_ : it) cerr << _ << " "; cerr << endl;}
#else
#define dbg(...) (void)0
#define dbgv(x) (void)0
#define dbga(arr, len) (void)0
#define dbgi(it) (void)0
#endif

using ll = long long;
using dbl = long double;
using pii = pair<int, int>;

char buf[105];
string scan_token()
{
    scanf("%s", buf);
    return buf;
}

string normalize(string s)
{
    for (char& c : s)
    {
        if (isupper(c))
            c = tolower(c);
        if (c == 'o')
            c = '0';
        if (c == 'l' || c == 'i')
            c = '1';
    }
    return s;
}

void solve()
{
    string my = normalize(scan_token());
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        string other = normalize(scan_token());
        if (my == other)
        {
            puts("No");
            return;
        }
    }
    puts("Yes");
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    solve();

    dbg("\n\ntime = %.3lf\n", (double)clock() / CLOCKS_PER_SEC);
}