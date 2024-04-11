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
string s;
int x[1000];

int main() {
    cin >> n;
    cin >> s;
    x[0] = 1;
    for (int i = 1; i < n; i++) {
        if (s[i - 1] == 'R') x[i] = x[i - 1] + 1; else
        if (s[i - 1] == '=') x[i] = x[i - 1]; else {
            x[i] = 1;
            if (x[i - 1] == 1) {
                x[i - 1]++;
                int j = i - 2;
                while (j >= 0 && x[j] >= x[j + 1] - 1 && x[j] <= x[j + 1]) {
                    x[j]++;
                    j--;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) printf ("%d ", x[i]);
    printf ("\n");
    return 0;
}