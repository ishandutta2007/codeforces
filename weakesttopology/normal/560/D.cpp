#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define mp(x, y) make_pair(x, y)

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

string A, B;

bool equal(int s, int t, int n)
{
    for (int i = 0; i < n; ++i)
        if (A[s + i] != B[t + i])
            return false;

    return true;
}

bool equivalent(int s, int t, int n)
{
    if (n % 2)
        return equal(s, t, n);

    int h = n / 2;
    if (
        (equivalent(s, t, h) && equivalent(s + h, t + h, h)) ||
        (equivalent(s, t + h, h) && equivalent(s + h, t, h))
    )
        return true;

    return false;
}

int main()
{ _
    cin >> A >> B;
    int n = A.size();

    if (equivalent(0, 0, n))
        cout << "YES\n";
    else
        cout << "NO\n";
    exit(0);
}