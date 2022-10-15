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
    int Q; cin >> Q;
    while (Q--)
    {
        int n; cin >> n;

        bool x = 0;
        int ones = 0;
        for (int i = 0; i < n; ++i)
        {
            string S; cin >> S;
            x = x || (S.size() % 2);

            for (auto c : S)
                ones += c == '1';
        }

        cout << n - !x * (ones % 2) << endl;
    }
    exit(0);
}