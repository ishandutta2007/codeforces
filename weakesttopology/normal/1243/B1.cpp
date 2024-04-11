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
    int k; cin >> k;
    while (k--)
    {
        int n; cin >> n;
        string s, t; cin >> s >> t;

        map<pair<char, char>, int> H;

        for (int i = 0; i < n; ++i)
        {
            if (H.count({s[i], t[i]}) && s[i] != t[i])
            {
                int j = H[make_pair(s[i], t[i])];

                char c = s[i];
                s[i] = t[j];
                t[j] = c;

                break;
            }
            else
                H[make_pair(s[i], t[i])] = i;
        }

        if (s == t)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    exit(0);
}