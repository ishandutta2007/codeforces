#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef long long ll;
typedef unsigned long long ull;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main()
{ _
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        queue<int> p[2] = { queue<int>() };

        for (int i = 0; i < (int)s.size(); ++i)
        {
            int x = s[i] - '0';
            p[x % 2].push(x);
        }

        vi ans;
        while (not p[0].empty() && not p[1].empty())
        {
            if (p[0].front() < p[1].front())
            {
                ans.pb(p[0].front());
                p[0].pop();
            }
            else
            {
                ans.pb(p[1].front());
                p[1].pop();
            }
        }

        while (not p[0].empty())
        {
            ans.pb(p[0].front());
            p[0].pop();
        }

        while (not p[1].empty())
        {
            ans.pb(p[1].front());
            p[1].pop();
        }

        for (auto d : ans)
            cout << d;
        cout << endl;
    }
    exit(0);
}