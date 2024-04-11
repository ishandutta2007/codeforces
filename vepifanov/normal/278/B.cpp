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
string s;
set<string> all;

string gen (string s, int n) {
    if (n == 0) {
        if (all.find (s) == all.end ()) re s;
        re "";
    }
    for (char c = 'a'; c <= 'z'; c++) {
        string res = gen (s + c, n - 1);
        if (res != "") re res;
    }
    re "";
}

int main () {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < sz (s); j++)
            for (int k = 1; j + k <= sz (s); k++)
                all.insert (s.substr (j, k));
    }
    string ans;
    for (int i = 1; ; i++) {
        ans = gen ("", i);
        if (ans != "") break;
    }
    cout << ans << endl;
    return 0;
}