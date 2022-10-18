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

const int MAXN = 1005;

int n, m;
bool avail[MAXN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> n >> m;

    if (m == 0) {
        cout << 1;
        return 0;
    }

    for(int i = 0; i < n; ++i)
        avail[i] = true;

    int cur = 0;
    for(int i = 0; i < m; ++i) {
        if (!avail[cur])
            cur = (cur+1)%n;
        avail[cur] = false;
        cur = (cur+2)%n;
    }

    int ans = 0;
    for(int i = 0; i < n; ++i)
        if (avail[i] && !avail[(i+1)%n])
            ++ans;

    cout << ans;

    return 0;
}