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
#define oo 1000000007

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int m, n, f[maxN];
string s;
deque<int> q;
bool choose[maxN];


int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &m);
    cin >> s;
    n = s.length();
    fto(i, 0, n-1) {
        while (!q.empty() && mp(s[i], -i) < mp(s[q.front()], -q.front())) q.pop_front();
        q.push_front(i);
        while (!q.empty() && q.back() <= i-m) q.pop_back();
        f[i] = q.back();
    }

//    fto(i, 0, n-1) printf("%d ", f[i]);
    int i = -1;
    string ans;
    do {
        i = f[i+m];
        choose[i] = true;
        ans += s[i];
//        debug(i);
    } while (i+m < n);

    char c = *max_element(ans.begin(), ans.end());

    fto(j, 0, n-1) {
        if (!choose[j] && s[j] < c) ans.pb(s[j]);
    }

    sort(ans.begin(), ans.end());
    cout << ans;


    return 0;
}