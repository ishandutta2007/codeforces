#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define debug(x) cerr << #x << " == " << (x) << '\n';

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
    int n; cin >> n;

    bool impossible = false;

    map<int, int> H;

    set<int> O;
    vi X;
    int last = 0;
    for (int i = 0; i < n; ++i)
    {
        int a; cin >> a;

        if (a > 0)
        {
            if (O.count(a) || H[a])
            {
                impossible = true;
                break;
            }
            else
            {
                O.insert(a);
                H[a]++;
            }
        }
        else if (a < 0)
        {
            if (O.count(-a) == 0)
            {
                impossible = true;
                break;
            }
            else
                O.erase(-a);
        }

        if (O.empty())
        {
            X.pb(i + 1 - last);
            last = i + 1;
            H.clear();
        }
    }

    if (impossible || not O.empty())
        cout << -1 << endl;
    else
    {
        cout << X.size() << endl;
        for (auto x : X)
            cout << x << " ";
        cout << endl;
    }

    exit(0);
}