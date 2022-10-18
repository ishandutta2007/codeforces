//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
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
#define ll long long
#define maxN 500005
#define oo 1000000000000007LL

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}


void fastCin(string &s) {
    char tmp[maxN];
    scanf("%s", tmp);
    s.assign(tmp);
}

int n;
string s[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) fastCin(s[i]), s[i] = s[i].substr(1);

    fdto(i, n-1, 1) {
        int j = 0; bool lo = false;
        while (j < s[i].length() && j < s[i+1].length() && s[i][j] <= s[i+1][j]) {
            if (s[i][j] < s[i+1][j]) {lo = true; break;}
            ++j;
        }
        if (!lo) s[i] = s[i].substr(0, j);
        //printf("%d %d\n", i, j);
    }

    fto(i, 1, n) printf("#%s\n", s[i].c_str());


    return 0;
}