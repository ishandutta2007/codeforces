//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i,  r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define fordit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 200005

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int q;
ll t[maxN], u[maxN], v[maxN], w[maxN];
map<pair<ll, ll>, ll> a;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &q);

    fto(i, 1, q) {
        cin >> t[i];
        if (t[i] == 1) {
            cin >> u[i] >> v[i] >> w[i];
            if (u[i] > v[i]) swap(u[i], v[i]);
            while (u[i] < v[i]) {
                a[mp(v[i]/2, v[i])] += w[i];
                v[i] /= 2;
                if (v[i] < u[i]) swap(u[i], v[i]);
            }
        }
        else {
            cin >> u[i] >> v[i];
            if (u[i] > v[i]) swap(u[i], v[i]);
            ll sum = 0;
            while (u[i] < v[i]) {
                sum += a[mp(v[i]/2, v[i])];
                v[i] /= 2;
                if (v[i] < u[i]) swap(u[i], v[i]);
            }
            cout << sum << endl;
        }
    }

    return 0;
}