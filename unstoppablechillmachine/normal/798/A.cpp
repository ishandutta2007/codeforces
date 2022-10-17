#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const INF=1e9 + 1;
ll const BINF=1e18 + 1;
int const MAXN = 1e6  + 10;
ld const EPS = -0.0000000000000001;

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

string s, s1;

bool check(string s)
{
    fore(i, s.size() / 2)
    {
        if (s[i] != s[s.size() - i - 1]) return false;
    }
    return true;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    cin >> s;
    fore(i, s.size())
    {
        fore(j, 26)
        {
            if (s[i] == 'a' + j) continue;
            s1 = s;
            s1[i] = j + 'a';
            if (check(s1))
            {
                cout << "YES";
                exit(0);
            }
        }
    }

    cout << "NO";





    return 0;
}