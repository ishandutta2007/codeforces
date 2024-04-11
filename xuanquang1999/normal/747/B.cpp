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
#define maxN 505
#define oo 1000000000000000007LL

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

int n, cnt[256];
char s[maxN], ch[4] = {'A', 'G', 'C', 'T'};

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    scanf("%s", s);
    if (n%4 != 0) {
        puts("===");
        return 0;
    }

    fto(i, 0, n-1) {
        if (s[i] != '?') ++cnt[s[i]];
    }

    fto(j, 0, 3) {
        if (cnt[ch[j]] > n/4) {
            puts("===");
            return 0;
        }
    }
    fto(i, 0, n-1) {
        if (s[i] == '?') {
            fto(j, 0, 3) {
                if (cnt[ch[j]] < n/4) {
                    ++cnt[ch[j]];
                    s[i] = ch[j];
                    break;
                }
            }
            if (s[i] == '?') {
                puts("===");
                return 0;
            }
        }
    }

    printf("%s", s);


    return 0;
}