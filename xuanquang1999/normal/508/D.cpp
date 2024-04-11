using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define fdto(i, r, l) for(int i = r; i >= l; --i)
#define fto(i, l, r) for(int i = l; i <= r; ++i)
#define forit(it, type, var) for(type::iterator it = var.begin(); it != var.end(); it++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 5005

int n, E, degin[maxN], degout[maxN], start[maxN];
vector<int> ke[maxN];
map<string, int> m;
map<int, string> rm;
list<int> cyc;

void addtomap(string s) {
    if (!m[s]) {
        m[s] = ++n;
        rm[n] = s;
    }
}

void EulerTour(list<int>::iterator it, int u) {
    for(; start[u] < ke[u].size(); ) {
        int v = ke[u][start[u]++];
        EulerTour(cyc.insert(it, v), v);
    }
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input1.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &E);
    fto(i, 1, E) {
        char s[3];
        scanf("%s", s);
        string s1, s2;
        s1.assign(s, 0, 2);
        s2.assign(s, 1, 2);
        addtomap(s1);
        addtomap(s2);
        ke[m[s1]].pb(m[s2]);
        ++degin[m[s2]]; ++degout[m[s1]];
    }
    int cnts = 0, cntt = 0;
    fto(u, 1, n)
        if (degin[u] > degout[u]+1 || degin[u]+1 < degout[u]) {
            puts("NO");
            return 0;
        }
        else if (degin[u] > degout[u]) ++cnts;
        else if (degin[u] < degout[u]) ++cntt;

    if (cnts > 1 || cntt > 1) {
        puts("NO");
        return 0;
    }
    int s = 0;

    fto(u, 1, n)
        if (degout[u] > degin[u]) {
            s = u;
            break;
        }

    if (s == 0) s = 1;
    EulerTour(cyc.begin(), s);

    if (cyc.size() < E) puts("NO");
    else {
        puts("YES");
        cyc.reverse();
        cout << rm[s];
        forit(it, list<int>, cyc) printf("%c", rm[*it][1]);
    }

    return 0;
}