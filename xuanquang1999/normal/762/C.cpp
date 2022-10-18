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

char s[maxN], t[maxN];
int n, m, fl[maxN], fr[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%s%s", s, t);
    m = strlen(s); n = strlen(t);

    int j = 0;
    fto(i, 0, m-1) {
        if (j < n && s[i] == t[j]) fl[i] = ++j;
        else fl[i] = fl[i-1];
    }

    j = n-1;
    fdto(i, m-1, 0) {
        if (j >= 0 && s[i] == t[j]) fr[i] = fr[i+1]+1, --j;
        else fr[i] = fr[i+1];
    }

//    fto(i, 0, m-1) printf("%d %d\n", fl[i], fr[i]);

    int pos = -1, ans = fr[0];

    if (fl[m-1] > ans) pos = m-1, ans = fl[m-1];

    fto(i, 0, m-2) {
        if (fl[i]+fr[i+1] > ans) {
            ans = fl[i]+fr[i+1];
            pos = i;
        }
    }

    string s1;
    j = 0;
    fto(i, 0, pos) {
        if (j < n && s[i] == t[j]) {
            s1 += s[i];
            ++j;
        }
    }

    string s2;
    int j2 = n-1;
    fdto(i, m-1, pos+1) {
        if (j2 >= j && s[i] == t[j2]) {
            s2 += s[i];
            --j2;
        }
    }

    reverse(s2.begin(), s2.end());

    if (s1+s2 == "") puts("-");
    else printf("%s", (s1+s2).c_str());



    return 0;
}