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
int r, c;

char h[5000001];
int p[1000000][21];
int l[1000000];
string s[1000000];

int main () {
    scanf ("%d%d%d", &n, &r, &c); c++;
    for (int i = 0; i < n; i++) {
        scanf (" %s", h);
        s[i] = string (h);
        l[i] = sz (s[i]) + 1;
    }
    for (int i = 0, j = 0, sum = 0; i < n; i++) {
        while (j < n && sum + l[j] <= c) {
            sum += l[j];
            j++;
        }
        p[i][0] = j;
        if (j > i) sum -= l[i]; else j++;
    }
    p[n][0] = n;                                    
    for (int t = 0; t < 20; t++) {
        p[n][t + 1] = n;
        for (int i = 0; i < n; i++)
            p[i][t + 1] = p[p[i][t]][t];
    }
    int ans = 0, pos = 0;
    for (int i = 0; i < n; i++) {
        int j = i, R = r, k = 20;
        while (R)
            if (R < (1 << k))
                k--;
            else {
                R -= (1 << k);
                j = p[j][k];
            }
        if (j - i > ans) {
            ans = j - i;
            pos = i;
        }
    }
    for (int i = 0; i < r; i++) {
        int j = p[pos][0];
        if (pos == j) break;
        for (int k = pos; k < j; k++) {
            if (k > pos) printf (" ");
            printf ("%s", s[k].c_str ());
        }   
        printf ("\n");
        pos = j;
    }
    return 0;
}