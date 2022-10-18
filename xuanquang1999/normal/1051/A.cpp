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
#define sample seriouslybruhyoujustwastedmy2minutestowritethismacro

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

const int MAXN = 105;

int nTest, n;
string s, t, sample[6] = {"Aa0", "A0a", "a0A", "aA0", "0aA", "0Aa"};

bool check(string s) {
    bool lo = false, hi = false, num = false;
    fto(i, 0, n-1) {
        if (s[i] >= 'a' && s[i] <= 'z') lo = true;
        if (s[i] >= 'A' && s[i] <= 'Z') hi = true;
        if (s[i] >= '0' && s[i] <= '9') num = true;
    }
    return (lo && hi && num);
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> nTest;
    fto(iTest, 1, nTest) {
        cin >> s;
        n = s.length();

        string ans;
        int minLen = n+1;
        fto(i, 0, n-1) {
            fto(len, 0, 3) {
                fto(k, 0, 5) {
                    t = s;
                    fto(j, 0, len-1) t[i+j] = sample[k][j];
                    if (check(t) && len < minLen) {
                        ans = t;
                        minLen = len;
                    }
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}