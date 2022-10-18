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
#define maxN 5005
#define oo 1000000007

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

int n, m, t[maxN], u[maxN], x[maxN], y[maxN], cur[maxN];
string val[maxN];
char tmp[maxN];
map<string, int> ma;

int Try(int j, int a) {
    memset(cur, 0, sizeof cur);
    cur[ma["?"]] = a;
    fto(i, 1, n) {
        if (t[i] == 0) cur[u[i]] = val[i][j]-'0';
        if (t[i] == 1) cur[u[i]] = cur[x[i]]&cur[y[i]];
        if (t[i] == 2) cur[u[i]] = cur[x[i]]|cur[y[i]];
        if (t[i] == 3) cur[u[i]] = cur[x[i]]^cur[y[i]];
    }

    int res = -cur[ma["?"]];
    fto(i, 1, ma.size()) res += cur[i];
    return res;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    fto(i, 1, n) {
        string c1, c2;
        fastCin(c1);
        fastCin(c2);
        fastCin(c2);
        if (!ma[c1]) ma[c1] = ma.size();
//        debug(c1);
//        debug(c2);
        u[i] = ma[c1];
        if (c2[0] == '0' || c2[0] == '1') {
            t[i] = 0; val[i] = c2;
        } else {
            string o, c3;
            fastCin(o);
            fastCin(c3);
//            debug(o);
//            debug(c3);
            if (!ma[c2]) ma[c2] = ma.size();
            if (!ma[c3]) ma[c3] = ma.size();
            x[i] = ma[c2]; y[i] = ma[c3];

            if (o == "AND") t[i] = 1;
            if (o == "OR") t[i] = 2;
            if (o == "XOR") t[i] = 3;
        }
    }
    if (!ma["?"]) ma["?"] = ma.size();

    //forit(it, ma) printf("%s %d\n", it->ff.c_str(), it->ss);

    string ansMin, ansMax;
    fto(j, 0, m-1) {
        int sum1 = Try(j, 0), sum2 = Try(j, 1);
        if (sum1 < sum2) ansMin += '0', ansMax += '1';
        else if (sum1 > sum2) ansMin += '1', ansMax += '0';
        else if (sum1 == sum2) ansMin += '0', ansMax += '0';
    }

    printf("%s\n%s\n", ansMin.c_str(), ansMax.c_str());

    return 0;
}