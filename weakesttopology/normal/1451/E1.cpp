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

int qxor(int i, int j)
{
    cout << "XOR " << i + 1 << " " << j + 1 << endl;
    int res; cin >> res;
    return res;
}

int qand(int i, int j)
{
    cout << "AND " << i + 1 << " " << j + 1 << endl;
    int res; cin >> res;
    return res;
}

int qor(int i, int j)
{
    cout << "OR " << i + 1 << " " << j + 1 << endl;
    int res; cin >> res;
    return res;
}

int main()
{
    int n; cin >> n;

    vector ans(n, 0);

    for (int i = 1; i < n; ++i)
        ans[i] = qxor(0, i);

    int and01 = qand(0, 1);

    int and02 = qand(0, 2);

    int and12 = qand(1, 2);

    int or01 = ans[1] + and01;

    int or02 = ans[2] + and02;

    int or12 = (ans[1] ^ ans[2]) + and12;

    int sum01 = or01 + and01;

    int sum02 = or02 + and02;

    int sum12 = or12 + and12;

    ans[0] = (sum01 + sum02 - sum12) / 2;

    for (int i = 1; i < n; ++i)
        ans[i] ^= ans[0];

    cout << "!";
    for (int i = 0; i < n; ++i) cout << " " << ans[i];
    cout << endl;

    exit(0);
}