#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
#define size(X) (int)size(X)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

void type1(string& s, int i)
{
    assert(1 <= i && i < size(s) - 1);
    cout << "L " << i + 1 << endl;
    string r = s.substr(1, i);
    reverse(all(r));
    s.insert(begin(s), all(r));
}

void type2(string& s, int i)
{
    assert(1 <= i && i < size(s) - 1);
    cout << "R " << i + 1 << endl;
    string r = s.substr(i, (size(s) - 2) - i + 1);
    reverse(all(r));
    s.insert(end(s), all(r));
}

int main()
{ _
    string s; cin >> s;

    cout << 3 << endl;

    type2(s, size(s) - 2);
    type1(s, size(s) - 2);
    type1(s, 1);

    string r = s;
    reverse(all(r));

    // debug(s);

    assert(s == r);

    exit(0);
}