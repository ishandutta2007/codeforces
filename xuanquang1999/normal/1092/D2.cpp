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
const int MAXN = 200005;

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

int n, a[MAXN];

bool solve(int l, int r) {
    stack<int> st;
    fto(i, l, r) {
        if (!st.empty() && st.top() == a[i])
            st.pop();
        else if (!st.empty() && st.top() < a[i])
            return false;
        else
            st.push(a[i]);
    }
    return st.empty();
}

int main () {
    scanf("%d", &n);
    fto(i, 0, n-1) scanf("%d", &a[i]);

    int maxA = *max_element(a, a+n);

    int last = 0;
    fto(i, 0, n) {
        if (i == n || a[i] == maxA) {
            if (!solve(last, i-1)) {
                puts("NO");
                return 0;
            }
            last = i+1;
        }
    }

    puts("YES");

    return 0;
}