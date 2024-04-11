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

void fail()
{
    cout << -1 << endl;
    exit(0);
}

int main()
{ _
    string s; cin >> s;

    int n = size(s);

    int k = n - 1;

    while (s[k] != '#') --k;

    int prefix = 0, num = 0;

    for (int i = 0; i < k; ++i)
    {
        prefix += s[i] == '(' ? 1 : -1;

        num += s[i] == '#';

        if (prefix < 0) fail();
    }

    int suffix = 0;

    for (int i = k + 1; i < n; ++i)
    {
        suffix += s[i] == '(' ? 1 : -1;

        if (prefix - 1 + suffix < 0) fail();
    }

    int suffix_backwards = 0;

    for (int i = n - 1; i > k; --i)
    {
        suffix_backwards += s[i] == ')' ? 1 : -1;

        // debug(suffix_backwards);

        if (suffix_backwards < 0) fail();
    }

    if (suffix > 0) fail();

    if (prefix + suffix <= 0) fail();

    for (int i = 0; i < num; ++i) cout << 1 << endl;

    cout << prefix + suffix << endl;

    exit(0);
}