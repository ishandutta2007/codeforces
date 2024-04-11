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

int n, m, a[maxN], cntOdd, cntEven, cntChg;
set<int> s;
vector<int> toC, odd, even;

void addEven(int i) {
    if (even.empty()) {
        puts("-1");
        exit(0);
    }
    a[i] = *even.rbegin();
    even.pop_back();
    ++cntChg; ++cntEven;
}

void addOdd(int i) {
    if (odd.empty()) {
        puts("-1");
        exit(0);
    }
    a[i] = *odd.rbegin();
    odd.pop_back();
    ++cntChg; ++cntOdd;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    fto(i, 1, n) {
        scanf("%d", &a[i]);
        if (s.count(a[i])) toC.pb(i);
        else {
            if (a[i]%2 == 0) ++cntEven;
            else ++cntOdd;
            s.insert(a[i]);
        }
    }

    fto(x, 1, min(m, 4*n)) {
        if (!s.count(x)) {
            if (x%2 == 0) even.pb(x);
            else odd.pb(x);
        }
    }
//    forit(it, toC) printf("%d ", *it);
//    puts("");
//    forit(it, s) printf("%d ", *it);
//    puts("");
//    forit(it, odd) printf("%d ", *it);
//    puts("");
//    forit(it, even) printf("%d ", *it);
//    puts("");

    forit(it, toC) {
        if (cntOdd < cntEven) addOdd(*it);
        else addEven(*it);
    }

    fto(i, 1, n) {
        if (cntOdd < cntEven && a[i]%2 == 0) addOdd(i), --cntEven;
        if (cntOdd > cntEven && a[i]%2 == 1) addEven(i), --cntOdd;
    }

    printf("%d\n", cntChg);
    fto(i, 1, n) printf("%d ", a[i]);

    return 0;
}