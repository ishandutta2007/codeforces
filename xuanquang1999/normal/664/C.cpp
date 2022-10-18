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
#define maxN 105

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

ll last, k;
int n;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    int nTest;
    scanf("%d\n", &nTest);
    fto(iTest, 1, nTest) {
        scanf("IAO'");
        string s;
        getline(cin, s);
        stringstream ss(s);
        ss >> n;
        last = 1988; k = 0; ll e10 = 1;
        fto(i, 1, s.length()) {
            k += (n%10)*e10;
            n /= 10; e10 *= 10;
            if (k > last%e10) {
                last = (last/e10)*e10 + k;
            }
            else {
                last = (last/e10+1)*e10 + k;
            }
        }
        cout << last << endl;
    }

    return 0;
}