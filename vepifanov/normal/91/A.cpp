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
string a, b;

int last[26];
int next[10000][26];

int main () {
    cin >> a >> b;  
    n = sz (a);
    m = sz (b);
    a += a;
    for (int j = 0; j < 26; j++) last[j] = -1;
    for (int i = 2 * n - 1; i >= 0; i--) {
        last[a[i] - 'a'] = i;
        if (i < n)
            for (int j = 0; j < 26; j++)
                if (last[j] != -1)
                    next[i][j] = last[j] - i;
                else
                    next[i][j] = -1;    
    }
    ll cur = -1;
    for (int i = 0; i < m; i++)
        if (next[(cur + 1) % n][b[i] - 'a'] != -1) 
            cur += 1 + next[(cur + 1) % n][b[i] - 'a'];
        else {
            printf ("-1\n");
            re 0;
        }   
    printf ("%d\n", (int)((cur + n) / n));
    return 0;
}