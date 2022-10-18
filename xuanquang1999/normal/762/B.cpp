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
#define maxN 300005
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

int a, b, c, n, cnt;
vector<int> p1, p2, p3;
ll sum;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d", &a, &b, &c);
    scanf("%d", &n);
    fto(i, 1, n) {
        int p;
        char s[5];
        scanf("%d%s", &p, s);
        if (s[0] == 'U') p1.pb(p);
        else p2.pb(p);
    }

    sort(p1.begin(), p1.end());
    sort(p2.begin(), p2.end());

    forit(it, p1) {
        if (a) {
            ++cnt;
            sum += *it;
            --a;
        }
        else p3.pb(*it);
    }

    forit(it, p2) {
        if (b) {
            ++cnt;
            sum += *it;
            --b;
        }
        else p3.pb(*it);
    }

    sort(p3.begin(), p3.end());

    forit(it, p3) {
        if (c) {
            ++cnt;
            sum += *it;
            --c;
        }
    }

    cout << cnt << " " << sum;

    return 0;
}