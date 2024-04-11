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
#define maxN 100005

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int q;
map<string, int> m;

void update(string s, int p) {
    reverse(s.begin(), s.end());
    fto(i, 0, s.length()-1) {
        s[i] = (s[i]-'0')%2 + '0';
    }
    while (s.length() < 18) s += '0';
    m[s] += p;
}

int query(string s) {
    reverse(s.begin(), s.end());
    while (s.length() < 18) s += '0';
    return m[s];
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &q);
    fto(i, 1, q) {
        string t, s;
        cin >> t >> s;
        if (t[0] == '+') update(s, 1);
        else if (t[0] == '-') update(s, -1);
        else if (t[0] == '?') printf("%d\n", query(s));
    }

    return 0;
}