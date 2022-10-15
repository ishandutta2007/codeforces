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

    int n = size(s);

    vector<string> words;

    auto valid = [&](int i) { return s[i] != ',' && s[i] != ';'; };

    for (int i = 0; i < n; ++i)
    {
        if (valid(i))
        {
            int j = i;
            while (j + 1 < n && valid(j + 1)) ++j;
            words.push_back(s.substr(i, j - i + 1));
            i = j;
        }
        else if (i == 0 || not valid(i - 1))
        {
            words.push_back(string());
        }
    }

    if (not valid(n - 1)) words.push_back(string());

    vector<string> a, b;

    for (auto& s : words)
    {
        bool integer = not empty(s);
        for (auto c : s) integer = integer && isdigit(c);
        if (size(s) > 1 && s[0] == '0')  integer = false;
        if (integer) a.push_back(s);
        else b.push_back(s);
    }

    for (auto v : { a, b })
    {
        if (empty(v)) cout << "-" << endl;
        else
        {
            cout << '"' << v[0];
            for (int i = 1; i < size(v); ++i) cout << "," << v[i];
            cout << '"' << endl;
        }
    }

    exit(0);
}