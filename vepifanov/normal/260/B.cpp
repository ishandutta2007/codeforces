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

const int mm[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int n;
int m;
map<string, int> all;
string s;

int cool (string s) {
    if (s[2] != '-' || s[5] != '-') re 0;
    s.erase (2, 1);
    s.erase (4, 1);
    for (int i = 0; i < 8; i++)
        if (!(s[i] >= '0' && s[i] <= '9'))
            re 0;
    int d = (s[0] - '0') * 10 + s[1] - '0';
    int m = (s[2] - '0') * 10 + s[3] - '0';
    int y = (((s[4] - '0') * 10 + s[5] - '0') * 10 + s[6] - '0') * 10 + s[7] - '0';
    if (y >= 2013 && y <= 2015 && m >= 1 && m <= 12 && d >= 1 && d <= mm[m - 1]) re 1;
    re 0;
}

int main () {
    cin >> s;
    for (int i = 0; i + 10 <= sz (s); i++)
        if (cool (s.substr (i, 10)))
            all[s.substr (i, 10)]++;
    string res = "";
    int ans = 0;
    for (map<string, int>::iterator it = all.begin (); it != all.end (); it++)
        if (it->se > ans) {
            ans = it->se;
            res = it->fi;
        }
    cout << res << endl;
    return 0;
}