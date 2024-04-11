#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
#define size(X) (int)std::size(X)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int main()
{ _
    string s; cin >> s;

    int v = 0, h = 0;

    for (auto c : s)
    {
        if (c == '0')
        {
            v += 1;
            cout << "1 " << v << endl;
        }
        else
        {
            h += 2;
            cout << "4 " << h - 1 << endl;
        }

        v %= 4, h %= 4;
    }

    exit(0);
}