//84104971101048411497 - Can you guess what does this mean?
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef complex<double> point;
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i,  r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define forrit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define X real()
#define Y imag()
#define maxN 6005
#define oo 1000000007
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

string s;
int last[256], n;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> s; n = s.length();
    fto(c, 'a', 'z') last[c] = -1;
    fto(i, 0, n-1) last[s[i]] = max(last[s[i]], i);

    string ans;
    stack<char> st;

    int i = -1;
    fto(c, 'a', 'z') {
        while (!st.empty() && st.top() <= c) {
            ans += st.top(); st.pop();
        }
        fto(j, i+1, last[c]) {
            st.push(s[j]);
            while (!st.empty() && st.top() <= c) {
                ans += st.top(); st.pop();
            }
        }
        i = max(i, last[c]);
    }
    while (!st.empty()) {
        ans += st.top(); st.pop();
    }

    cout << ans;

    return 0;
}