#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define sz(a) (int)a.size()

const double PI = acos(-1.0);

double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a%b);
}

const int MAXN = 200005;
const int MAXK = 18;

int n, a[MAXN];

int main () {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
        scanf("%d", &a[i]);

    for(int hi = MAXK; hi >= 1; --hi) {
        vector<bool> span(1<<hi, false);
        span[0] = true;

        vector<int> basis;
        for(int i = 0; i < n; ++i) {
            if (a[i] >= (1<<hi) || span[a[i]])
                continue;

            basis.push_back(a[i]);

            vector<bool> nxt(1<<hi, false);
            for(int x = 0; x < (1<<hi); ++x)
                if (span[x])
                    nxt[x^a[i]] = nxt[x] = true;

            span = nxt;
        }

        if (basis.size() >= hi) {
            vector<string> grey;
            grey.push_back("0");
            grey.push_back("1");

            for(int i = 1; i < basis.size(); ++i) {
                int k = grey.size();
                for(int j = k-1; j >= 0; --j)
                    grey.push_back(grey[j]);
                for(int j = 0; j < k; ++j)
                    grey[j] += "0";
                for(int j = k; j < 2*k; ++j)
                    grey[j] += "1";
            }

            vector<int> ans;
            for(string s: grey) {
                int x = 0;
                for(int i = 0; i < basis.size(); ++i)
                    if (s[i] == '1')
                        x ^= basis[i];
                ans.push_back(x);
            }

            printf("%d\n", basis.size());
            for(int x: ans)
                printf("%d ", x);
            return 0;
        }
    }

    puts("0");
    puts("0");

    return 0;
}