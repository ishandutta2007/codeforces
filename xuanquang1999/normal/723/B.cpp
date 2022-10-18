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

int n;
string s;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    cin >> s;
    int cntOut = 0, cntIn = 0, cnt = 0;
    bool isIn = false;
    fto(i, 0, n) {
        if (i == n || s[i] == '_') {
            if (!isIn) cntOut = max(cntOut, cnt);
            else if (cnt > 0) ++cntIn;
            cnt = 0;
        }
        else if (s[i] == '(') {
            if (cnt > 0) cntOut = max(cntOut, cnt);
            isIn = true;
            cnt = 0;
        }
        else if (s[i] == ')') {
            if (cnt > 0) ++cntIn;
            isIn = false;
            cnt = 0;
        }
        else ++cnt;
    }

    printf("%d %d\n", cntOut, cntIn);

    return 0;
}