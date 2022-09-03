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
int a, b, ab, ba;

int main () {
    cin >> a >> b >> ab >> ba;
    string res = "";
    if (ab == ba + 1 && a >= ab && b >= ab) {
        string s = "";
        for (int i = 0; i < a - ab; i++) s += "4";
        for (int i = 0; i < ab; i++) s += "47";
        for (int i = 0; i < b - ab; i++) s += "7";
        if (res == "" || res > s) res = s;
    }
    if (ab == ba && a >= ab + 1 && b >= ab) {
        string s = "";
        for (int i = 0; i < a - ab - 1; i++) s += "4";
        for (int i = 0; i < ab; i++) s += "47";
        for (int i = 0; i < b - ab; i++) s += "7";
        s += "4";
        if (res == "" || res > s) res = s;
    }

    if (ab == ba && a >= ab && b >= ab + 1) {
        string s = "7";
        for (int i = 0; i < a - ba; i++) s += "4";
        for (int i = 0; i < ba; i++) s += "47";
        for (int i = 0; i < b - ab - 1; i++) s += "7";
        if (res == "" || res > s) res = s;
    }
    if (ab + 1 == ba && a >= ba && b >= ba) {
        string s = "7";
        for (int i = 0; i < a - ba; i++) s += "4";
        for (int i = 0; i < ba - 1; i++) s += "47";
        for (int i = 0; i < b - ba; i++) s += "7";
        s += "4";
        if (res == "" || res > s) res = s;
    }
    if (res == "") res = "-1";
    cout << res << endl;

    return 0;
}