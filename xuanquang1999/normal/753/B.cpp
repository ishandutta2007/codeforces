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
#define maxN 100005
#define oo 3000000000000000000LL
#define sz(s) int(s.size())
#define all(s) s.begin(), s.end()

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

int n;
vector<int> v;

int main () {
    string s = "0000";
    fto(i, 0, 3) {
        vector<int> v(10);
        fto(d, 0, 9) {
            s[i] = '0'+d;
            cout << s << endl;
            fflush(stdout);
            int b, c;
            cin >> b >> c;
            v[d] = b;
        }
        s[i] = '0' + (max_element(v.begin(), v.end())-v.begin());
    }

    cout << s << endl;
    fflush(stdout);

    return 0;
}