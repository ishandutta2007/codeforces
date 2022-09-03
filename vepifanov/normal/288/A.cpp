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

int main () {
    cin >> n >> m;
    if (m == 1 && n > 1 || m > n) {
        cout << "-1" << endl;
        re 0;
    }   
    if (m == 1) {
        cout << "a" << endl;
    } else {
        if ((n - m) & 1) {
            for (int i = 0; i < (n - m + 1) / 2; i++) cout << "ab";
            for (int i = 0; i < m; i++)
                if (i != 1)
                    cout << char (i + 'a');
        } else {
            for (int i = 0; i < (n - m) / 2; i++) cout << "ab";
            for (int i = 0; i < m; i++) cout << char (i + 'a');
        }
        cout << endl;
    }
    return 0;
}