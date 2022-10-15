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
    int q; cin >> q;
    while(q--)
    {
        string s, t; cin >> s >> t;

        int n = s.size();

        set<char> S;

        for (int i = 0; i < n; ++i)
            S.insert(s[i]);

        bool success = false;
        for (int i = 0; i < n; ++i)
        {
            if (S.count(t[i]))
            {
                cout << "YES" << endl;
                success = true;
                break;
            }
        }

        if (not success)
            cout << "NO" << endl;
    }
    exit(0);
}