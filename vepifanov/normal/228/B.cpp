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

int na, nb;
int ma, mb;
string sa[50], sb[50];

int main () {
    cin >> na >> ma;
    for (int i = 0; i < na; i++) cin >> sa[i];
    cin >> nb >> mb;
    for (int i = 0; i < nb; i++) cin >> sb[i];
    int ans = 0, xx, yy;
    for (int x = -50; x <= 50; x++)
        for (int y = -50; y <= 50; y++) {
            int cur = 0;
            for (int i = 0; i < na; i++)
                for (int j = 0; j < ma; j++)
                    if (i + x >= 0 && i + x < nb && j + y >= 0 && j + y < mb)
                        cur += int (sa[i][j] == '1' && sb[i + x][j + y] == '1');
            if (ans < cur) {
                ans = cur;
                xx = x;
                yy = y;
            }
        }
    printf ("%d %d\n", xx, yy);
    return 0;
}