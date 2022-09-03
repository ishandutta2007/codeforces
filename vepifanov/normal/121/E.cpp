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

const int LEN = 500;
const int MAX = (100000 + LEN - 1) / LEN;

int n, m, r = 0;
int q[50];
int luck[10001];
int cnt[MAX][10001];
int off[MAX], L[MAX], R[MAX], res[MAX];
int x[100000];
char w[100];

int cool (int x) {
    while (x) {
        if (x % 10 != 4 && x % 10 != 7) re 0;
        x /= 10;
    }
    re 1;
}

int main () {
    for (int i = 1; i <= 10000; i++) 
        if (cool (i)) {
            q[r++] = i;
            luck[i] = 1;
        }   
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
    int B = (n + LEN - 1) / LEN;
    for (int i = 0; i < B; i++) {
        int l = i * LEN, r = min ((i + 1) * LEN, n) - 1;
        L[i] = l;
        R[i] = r;
        for (int j = l; j <= r; j++) {
            res[i] += luck[x[j]];
            cnt[i][x[j]]++;
        }   
    }
    gets (w);
    for (int i = 0; i < m; i++) {
        scanf ("%s", w);
        if (w[0] == 'c') {
            int l, r;
            scanf ("%d%d\n", &l, &r); l--; r--; 
            int ans = 0;
            for (int j = 0; j < B; j++) {
                int cl = max (l, L[j]), cr = min (r, R[j]);
                if (cl > cr) continue;
                if (cl == L[j] && cr == R[j]) {
                    ans += res[j];
                } else {
                    for (int k = cl; k <= cr; k++)
                        if (luck[x[k] + off[j]])
                            ans++;
                }
            }
            printf ("%d\n", ans);
        } else {
            int l, r, d;
            scanf ("%d%d%d\n", &l, &r, &d); l--; r--;
            for (int j = 0; j < B; j++) {
                int cl = max (l, L[j]), cr = min (r, R[j]);
                if (cl > cr) continue;
                if (cl == L[j] && cr == R[j]) {
                    off[j] += d;
                    res[j] = 0;
                    for (int k = 0; k < ::r; k++)
                        if (q[k] - off[j] >= 0)
                            res[j] += cnt[j][q[k] - off[j]];
                } else {
                    for (int k = cl; k <= cr; k++) {
                        res[j] -= luck[x[k] + off[j]];
                        cnt[j][x[k]]--;
                        x[k] += d;
                        cnt[j][x[k]]++;
                        res[j] += luck[x[k] + off[j]];
                    }
                }
            }
        }
    }
    return 0;
}