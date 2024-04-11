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
    int n, k; cin >> n >> k;

    set<int> S;
    priority_queue<ii> Q;

    for (int i = 0; i < n; ++i)
    {
        int id; cin >> id;
        if (S.count(id) == 0)
        {
            if ((int)Q.size() == k)
            {
                ii x = Q.top(); Q.pop();
                S.erase(x.s);
            }
            S.insert(id);
            Q.push({-i, id});
        }
    }

    cout << S.size() << endl;

    vi out;

    while(not Q.empty())
    {
        ii x = Q.top(); Q.pop();
        out.pb(x.s);
    }

    while(not out.empty())
    {
        cout << out.back() << " ";
        out.pop_back();
    }
    cout << endl;

    exit(0);
}