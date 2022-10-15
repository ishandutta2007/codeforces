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

string oo(const string& s)
{
    string res;
    for (auto c : s)
    {
        if (c == 'u') (res += 'o') += 'o';
        else res += c;
    }
    return res;
}

string kh(string s)
{
    reverse(all(s));

    string res;

    for (auto c : s)
    {
        if (c == 'k' && not empty(res) && res.back() == 'h') continue;
        res += c;
    }

    reverse(all(res));

    return res;
}

int main()
{ _
    int n; cin >> n;

    vector<string> names;

    for (int i = 0; i < n; ++i)
    {
        string s; cin >> s;
        names.push_back(kh(oo(s)));
        // debug(names.back());
    }

    sort(all(names));

    names.erase(unique(all(names)), end(names));

    cout << size(names) << endl;

    exit(0);
}