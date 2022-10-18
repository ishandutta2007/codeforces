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
#define oo 1000000007

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

map<string, int> m;
string s, t;
int a, b;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    string dow[7] = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};
    int dom[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    fto(i, 0, 6) m[dow[i]] = i;

    cin >> s >> t;
    a = m[s], b = m[t];

    fto(i, 1, 11) {
        if ((a+dom[i])%7 == b) {
            puts("YES");
            return 0;
        }
    }

    puts("NO");

    return 0;
}