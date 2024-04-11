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

const int da[6] = {0, 0, 0, 1, 1, 2};
const int db[6] = {1, 2, 3, 2, 3, 3};

const int MAX = 400000;

int n;
int m;

ll w[6][8];
string s[4];
int res[8];

int main () {
    for (int i = 0; i < 6; i++) scanf ("%I64d", &w[i][7]);
    for (int i = 0; i < 6; i++) {
        int a = da[i], b = db[i];
        for (int j = 1; j < 8; j++)
            if (((j >> a) & 1) != ((j >> b) & 1)) w[i][j - 1] = 1;
    }
    for (int i = 0; i < 6; i++) {
        for (int j = i; j < 6; j++)
            if (w[i][j] != 0) {
                for (int k = 0; k < 8; k++) swap (w[i][k], w[j][k]);
                break;
            }
        for (int j = i + 1; j < 6; j++) {
            ll p = w[i][i];
            ll q = w[j][i];
            for (int k = i; k < 8; k++) w[j][k] = w[j][k] * p - w[i][k] * q;
        }
    }
    for (int t = 0; t <= MAX; t++) {
        int ok = 1;
        res[7] = t;
        for (int j = 5; j >= 0; j--) {
            ll tmp = w[j][7] - w[j][6] * t;
            for (int k = j + 1; k < 6; k++) tmp -= w[j][k] * res[k + 1];
            if (tmp % w[j][j] == 0) {
                tmp /= w[j][j];
                if (tmp < 0) {
                    ok = 0;
                    break;
                }
                res[j + 1] = tmp;
            } else { ok = 0; break; }
        }   
        if (ok) {
            for (int j = 1; j <= 7; j++) 
                for (int k = 0; k < res[j]; k++) {
                    for (int t = 0; t < 4; t++)
                        if ((j >> t) & 1)
                            s[t] += 'a';
                        else
                            s[t] += 'b';    
                }
            cout << sz (s[0]) << endl;
            for (int j = 0; j < 4; j++) cout << s[j] << endl;
            re 0;
        }
    }
    cout << "-1" << endl;
    return 0;
}