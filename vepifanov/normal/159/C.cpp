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
int m, k;
string s[2000];
int cnt[2000][26];

int main () {
    cin >> k >> s[0];
    n = sz (s[0]);
    for (int i = 0; i < k; i++) {
        s[i] = s[0];
        for (int j = 0; j < n; j++)
            cnt[i][s[0][j] - 'a']++;
    }   
    cin >> m;
    for (int t = 0; t < m; t++) {
        int x;
        string y;
        cin >> x >> y;
        int z = y[0] - 'a';
        for (int i = 0; i < k; i++)
            if (cnt[i][z] >= x) {
                for (int j = 0; j < sz (s[i]); j++)
                    if (s[i][j] - 'a' == z) {
                        x--;
                        if (x == 0) {
                            s[i].erase (j, 1);
                            cnt[i][z]--;
                            break;
                        }   
                    }
                break;
            } else x -= cnt[i][z];
    }
    for (int i = 0; i < k; i++) cout << s[i];
    cout << endl;
    return 0;
}