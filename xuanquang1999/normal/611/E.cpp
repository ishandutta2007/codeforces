//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
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
#define maxN 5005
#define MOD 1000000007

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

multiset<int> s;
int a, b, c, n, ans;

int findBest(int x) {
    if (s.empty()) return 0;
    multiset<int>::iterator it = s.upper_bound(x);
    if (it == s.begin()) return 0;
    return *(--it);
}

bool getBest(int x) {
    if (s.empty()) return false;
    multiset<int>::iterator it = s.upper_bound(x);
    if (it == s.begin()) return false;
    s.erase(s.find(*(--it)));
    return true;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    scanf("%d%d%d", &a, &b, &c);
    if (a > b) swap(a, b);
    if (a > c) swap(a, c);
    if (b > c) swap(b, c);
    fto(i, 1, n) {
        int x;
        scanf("%d", &x);
        s.insert(x);
    }

    if (*s.rbegin() > a+b+c) {
        puts("-1");
        return 0;
    }

    while (findBest(a+b+c) > findBest(b+c)) getBest(a+b+c), ++ans;
    while (findBest(b+c) > findBest(a+c)) getBest(b+c), getBest(a), ++ans;
    if (c >= a+b) {
        while (findBest(a+c) > findBest(c)) getBest(a+c), getBest(b), ++ans;
    }
    else {
//        printf("%d %d %d\n", a, b, c);
//        forit(it, s) printf("%d ", *it);
//        puts("");
        while (findBest(a+c) > findBest(a+b)) getBest(a+c), getBest(b), ++ans;
        while (findBest(a+b) > findBest(c)) getBest(a+b), getBest(c), ++ans;
    }

    while (!s.empty()) {
        getBest(c);
        if (findBest(b) > 0) getBest(a), getBest(b);
        else getBest(a+b);
        ++ans;
    }

    cout << ans;

    return 0;
}