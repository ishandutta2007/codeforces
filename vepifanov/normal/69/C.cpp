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

int n, K;
int m, q;
char s[10000];
map<string, int> cnt[100];
string x[100], y[100];
vector<pair<string, int> > v[100];

int main() {
    scanf ("%d%d%d%d", &K, &n, &m, &q); 
    gets (s);
    for (int i = 0; i < n; i++) {
        gets (s);
        x[i] = string (s);
    }
    for (int i = 0; i < m; i++) {
        gets (s);
        for (int j = 0; s[j]; j++)
            if (s[j] == ':' || s[j] == ',')
                s[j] = ' ';
        stringstream in (s);
        in >> y[i];
        string tmp;
        int t;
        while (in >> tmp) {
            in >> t;
            v[i].pb (mp (tmp, t));
        }
    }
    for (int i = 0; i < q; i++) {
        gets (s);
        stringstream in (s);
        string z;
        int t;
        in >> t >> z; t--;
        cnt[t][z]++;
        for (int j = 0; j < m; j++) {
            int ok = 1;
            for (int k = 0; k < sz (v[j]); k++)
                if (!cnt[t].count (v[j][k].fi) || cnt[t][v[j][k].fi] < v[j][k].se) {
                    ok = 0;
                    break;
                }
            if (ok) {
                for (int k = 0; k < sz (v[j]); k++) {
                    cnt[t][v[j][k].fi] -= v[j][k].se;
                    if (cnt[t][v[j][k].fi] == 0) cnt[t].erase (v[j][k].fi);
                }   
                cnt[t][y[j]]++; 
            }
        }
    }
    for (int i = 0; i < K; i++) {
        map<string, int>::iterator it;
        cout << sz (cnt[i]) << endl;
        for (it = cnt[i].begin (); it != cnt[i].end (); it++)
            cout << it->fi << " " << it->se << endl;
    }
    return 0;
}