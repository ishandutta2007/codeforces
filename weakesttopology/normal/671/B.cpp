#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define debug(x) cerr << #x << " == " << x << endl

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
    vi A(n);
    ll sum = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> A[i];
        sum += A[i];
    }

    sort(A.rbegin(), A.rend());

    int w = abs(A[0] - A[n - 1]);
    if (w == 0 || k == 0)
    {
        cout << w << endl;
        exit(0);
    }

    int M = INF;
    int C = 0;

    int r;
    for (r = 0; r < n; ++r)
    {
        ll diff = ll(r) * ll(M - A[r]);

        if (C + diff < k)
        {
            C += diff;
            M = A[r];
        }
        else
        {
            diff = k - C;
            C = k;
            M -= diff / r;
            break;
        }
    }

    sort(A.begin(), A.end());

    int m = 0;
    int l;
    for (l = 0; l < n; ++l)
    {
        ll diff = ll(l) * ll(A[l] - m);

        if (diff < C)
        {
            C -= diff;
            m = A[l];
        }
        else
        {
            diff = C;
            C = 0;
            m += diff / l;
            break;
        }
    }

    cout << max(M - m, sum % n > 0 ? 1 : 0) << endl;

    exit(0);
}