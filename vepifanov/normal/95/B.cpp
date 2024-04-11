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
#define pi 3.141592653589
#define sqrt(x) sqrt(abs(x))

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
string s, res = "";

int check (int i, int j) {
        if (n - i < abs (j)) re 0;
        if (j >= 0) {
                int a = 0, b = j, c = (n - i - j) / 2;
                a += c;
                b += c;
                for (int i = 0; i < b; i++) res += '7';
                for (int i = 0; i < a; i++) res += '4';
        } else {
                int a = -j, b = 0, c = (n - i + j) / 2;
                a += c;
                b += c;
                for (int i = 0; i < b; i++) res += '7';
                for (int i = 0; i < a; i++) res += '4';
        }
        re 1;
}

int go (int i, int j) {
        if (i == n) re int (j == 0);
        if (s[i] < '4' && check (i + 1, j + 1) || s[i] == '4' && go (i + 1, j + 1)) {
                res += '4';
                re 1;
        }
        if (s[i] < '7' && check (i + 1, j - 1) || s[i] == '7' && go (i + 1, j - 1)) {
                res += '7';
                re 1;
        }
        re 0;
}

int main() {
        cin >> s;
        n = sz (s);
        if (n & 1) {
                for (int i = 0; i < (n + 1) / 2; i++) printf ("4");
                for (int i = 0; i < (n + 1) / 2; i++) printf ("7");
                printf ("\n");
                re 0;
        }
        if (!go (0, 0)) {
                for (int i = 0; i < (n + 2) / 2; i++) printf ("4");
                for (int i = 0; i < (n + 2) / 2; i++) printf ("7");
                printf ("\n");
                re 0;
        } else {
                reverse (all (res));
                printf ("%s\n", res.c_str ());
        }
        return 0;
}