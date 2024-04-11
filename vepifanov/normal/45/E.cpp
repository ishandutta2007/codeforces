#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < n; i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define y0 y3487465
#define y1 y8687969

typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) {
    re x > 0 ? x : -x;
}

int n;
int m;
int ans = 0, cur = 0;
char ca[26], cb[26];
int ua[100], ub[100];
string a[100], b[100];

int check (int j, int k) {
    memset (ca, 0, sizeof (ca));
    memset (cb, 0, sizeof (cb));
    for (int i = 0; i < n; i++) {
        if (!ua[i] && i != j) ca[a[i][0] - 'A']++;
        if (!ub[i] && i != k) cb[b[i][0] - 'A']++;
    }
    int tmp = 0;
    for (int i = 0; i < 26; i++) tmp += min (ca[i], cb[i]);
    re int (ans == cur + tmp + int (a[j][0] == b[k][0]));
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ca[a[i][0] - 'A']++;
    }   
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        cb[b[i][0] - 'A']++;
    }
    for (int i = 0; i < 26; i++) ans += min (ca[i], cb[i]);
    cerr << ans << endl;
    string res = "";
    for (int i = 0; i < n; i++) {
        int p = -1, q = -1;
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                if (!ua[j] && !ub[k] && check (j, k))
                    if (p == -1 || a[p] + " " + b[q] + ", " > a[j] + " " + b[k] + ", ") {
                        p = j;
                        q = k;
                    }
        cur += int (a[p][0] == b[q][0]);
        ua[p] = ub[q] = 1;
        res += a[p] + " " + b[q];
        if (i + 1 < n) res += ", ";
    }
    cout << res << endl;
    return 0;
}