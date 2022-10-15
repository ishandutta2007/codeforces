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

class BIT
{
private:
    vi ft;
    int LSOne(int i) { return i & (-i); };
public:
    BIT(int n)
    {
        ft.assign(n + 1, 0);
    }
    int RSQ(int b)
    {
        int sum = 0;
        for (int i = b; i; i -= LSOne(i))
            sum += ft[i];
        return sum;
    }
    int RSQ(int a, int b)
    {
        return RSQ(b) - (a == 1 ? 0 : RSQ(a - 1));
    }
    void adjust(int k, int v)
    {
        for (int i = k; i < (int)ft.size(); i += LSOne(i))
            ft[i] += v;
    }
    int lowerbound(int x)
    {
        int n = ft.size();

        if (x <= RSQ(1))
            return 0;
        if (RSQ(n) < x)
            return -1;

        int left = 1, right = n;
        int mid = (left + right) / 2;

        while (left != mid)
        {
            if (RSQ(mid) < x)
                left = mid;
            else
                right = mid;

            mid = (left + right) / 2;
        }

        return right;
    }
};

int main()
{
    string S; cin >> S;
    vector<BIT> X(26, BIT((int)S.size()));

    for (int i = 0; i < 26; ++i)
    {
        char c = 'a' + i;
        for (int j = 0; j < (int)S.size(); ++j)
        {
            if (c == S[j])
                X[i].adjust(j + 1, 1);
        }
    }

    int q; cin >> q;

    for (int t = 0; t < q; ++t)
    {
        int type; cin >> type;
        if (type == 1)
        {
            int pos; cin >> pos;
            char c; cin >> c;
            X[S[pos - 1] - 'a'].adjust(pos, -1);
            X[c - 'a'].adjust(pos, 1);
            S[pos - 1] = c;
        }
        else
        {
            int l, r; cin >> l >> r;
            int num = 0;
            for (int i = 0; i < 26; ++i)
                num += X[i].RSQ(l, r) > 0;
            cout << num << endl;
        }
    }

    exit(0);
}