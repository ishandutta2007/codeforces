//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define forrit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 200005
#define maxK 20
#define oo 1000000007

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

template <class T>
void read(vector<T> &v) {
    T x;
    cin >> x;
    v.pb(x);
}

string s, t;
bool a[256][256];
int c[256];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> s >> t;
    int n = s.length();

    fto(i, 0, n-1) {
        if ((c[s[i]] != 0 && c[s[i]] != t[i]) || (c[t[i]] != 0 && c[t[i]] != s[i])) {
            puts("-1");
            return 0;
        }
        c[s[i]] = t[i]; c[t[i]] = s[i];
    }

    vector<ii> ans;
    fto(i, 'a', 'z') {
        if (c[i] != 0 && c[i] != i) {
            ans.pb(mp(i, c[i]));
            c[c[i]] = 0;
        }
    }

    printf("%d\n", ans.size());
    forit(it, ans) printf("%c %c\n", it->ff, it->ss);

    return 0;
}