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
#define maxN 1000005
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

string toS(char c[]) {
    string s;
    s.assign(c);
    return s;
}

char tmp;
vector<string> v[maxN];
int maxD = 1;

void readS(string &s) {
    s = "";
    char c;
    while (scanf("%c", &c) != EOF) {
        if (c == ',') return;
        s += c;
    }
}

void Solve(int h) {
    maxD = max(maxD, h);
    string s; int d;
    readS(s);
//    debug(s);
    scanf("%d%c", &d, &tmp);

    v[h].pb(s);
    fto(i, 1, d) Solve(h+1);
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    while (true) {
        string s; int d;
        readS(s);
        if (s == "") break;

        v[1].pb(s);
        scanf("%d%c", &d, &tmp);
//        cout << s << " " << d << endl;
        fto(i, 1, d) Solve(2);
    }

    printf("%d\n", maxD);
    fto(i, 1, maxD) {
        forit(it, v[i]) printf("%s ", (*it).c_str());
        puts("");
    }


    return 0;
}