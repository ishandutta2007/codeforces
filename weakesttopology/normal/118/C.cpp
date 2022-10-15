#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

struct custom_hash {
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return x + FIXED_RANDOM;
    }
};

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef long long ll;
typedef unsigned long long ull;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

string build(int n, int D[10], vi B, int p)
{
    for (int i = 0; i < n; ++i)
    {
        if (D[B[i]] && B[i] > p)
        {
            D[B[i]]--;
            B[i] = p;
        }
    }
    for (int i = n-1; i >= 0; --i)
    {
        if (D[B[i]] && B[i] < p)
        {
            D[B[i]]--;
            B[i] = p;
        }
    }

    string s;

    for (auto x : B)
        s.pb('0' + x);

    return s;
}

int cost(int C[10], int D[10], int k, int p)
{
    k -= min(k, C[p]);

    int sum = 0;

    for (int i = 1; i < 10; ++i)
    {
        if (p + i < 10)
        {
            int d = min(C[p+i], k);
            D[p + i] = d;
            sum += d * i;
            k -= d;
        }
        if (p - i >= 0)
        {
            int d = min(C[p-i], k);
            D[p - i] = d;
            sum += d * i;
            k -= d;
        }
    }
    return sum;
}

int main()
{ _
    int n, k; cin >> n >> k;
    vi B(n);

    int C[10] = { 0 };

    for (int i = 0; i < n; ++i)
    {
        char p; cin >> p;
        B[i] = int(p - '0');
        C[B[i]]++;
    }

    int m = n * 10;
    string ans;
    for (int p = 0; p < 10; ++p)
    {
        int D[10] = { 0 };
        int m1 = cost(C, D, k, p);
        string s = build(n, D, B, p);
        if (m1 < m || (m1 == m && s < ans))
        {
            m = m1;
            ans = s;
        }
    }

    cout << m << endl << ans << endl;

    exit(0);
}