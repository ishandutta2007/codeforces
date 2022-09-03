#include <cstdio>
#include <numeric>
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
#include <deque>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define fill(x,y) memset(x,y,sizeof(x))
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

int n;
int m;

char h[1000];

int main () {
    scanf ("%d", &n);
    gets (h);
    int cur = 0;
    string exc;
    int last = -1;
    for (int i = 0; i < n; i++) {
        gets (h);
        int ok = 0;
        for (int j = 0; h[j]; j++) {
            if (h[j] == 't' && h[j + 1] == 'r') ok = 1;
            if (h[j] == 't' && h[j + 1] == 'h') ok = 2;
            if (h[j] == 'c') ok = 3;
            if (h[j] != ' ') break;
        }   
        if (ok) {
            for (int j = 0; h[j]; j++) {
                if (h[j] == '(' || h[j] == ',' || h[j] == ')')
                    h[j] = ' ';
                if (h[j] == '"') break;
            }   
            if (ok == 3) {
                string msg = "";
                for (int j = 0; h[j]; j++)
                    if (h[j] == '"') {
                        for (int k = j + 1; h[k] != '"'; k++)
                            msg += h[k];
                        break;
                    }
                stringstream in (h);
                string s, t;
                in >> s >> t;
                if (cur == last) {
                    if (t == exc) {
                        cout << msg << endl;
                        re 0;
                    }
                    last--;
                }
                cur--;
            }
            if (ok == 2) {
                stringstream in (h);
                string s, t;
                in >> s >> t;
                exc = t;
                last = cur;
            }
            if (ok == 1) {
                cur++;
            }

        }
    }
    cout << "Unhandled Exception" << endl;
    return 0;
}