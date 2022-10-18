//84104971101048411497 - Can you guess what does this mean?
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef complex<double> point;
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
#define maxN 100005
#define MOD 1000
#define oo 1000000000000000007LL
#define sz(a) (int)a.size()

const double PI = acos(-1.0);

double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

const int K = 26;

struct Vertex {
    int nxt[K];
    int dep;
    bool leaf = false;
    Vertex(int dep = 0): dep(dep) {
        fill(begin(nxt), end(nxt), -1);
    }
};

int n;
vector<Vertex> t(1);

void add_string(string s) {
    int v = 0;
    for(char ch: s) {
        int c = ch-'a';
        if (t[v].nxt[c] == -1) {
            t[v].nxt[c] = t.size();
            t.pb(Vertex(t[v].dep+1));
        }
        v = t[v].nxt[c];
    }
    t[v].leaf = true;
}

vector<int> Calc(int u) {
    vector<int> token;
//    debug(u);
    fto(c, 0, K-1) {
        if (t[u].nxt[c] != -1) {
//            printf("%d %d\n", u, c);
            vector<int> sub = Calc(t[u].nxt[c]);
            token.insert(token.end(), sub.begin(), sub.end());
        }
    }

    if (t[u].leaf) token.pb(t[u].dep);
    else if (u > 0) {
        int p = max_element(token.begin(), token.end())-token.begin();
        token[p] = t[u].dep;
    }

    return token;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) {
        string s;
        cin >> s;
        add_string(s);
    }

    vector<int> ans = Calc(0);

    cout << accumulate(ans.begin(), ans.end(), 0);

    return 0;
}