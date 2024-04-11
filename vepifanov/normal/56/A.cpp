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

const string w[11] = {"ABSINTH", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE", "TEQUILA", "VODKA", "WHISKEY", "WINE"};

int n;
int m;

int get (string s) {
    int x = 0;
    for (int i = 0; i < sz (s); i++) x = x * 10 + s[i] - '0';
    re x;
}

int check (string s) {
    for (int i = 0; i < 11; i++)
        if (s == w[i])
            re 1;
    re 0;
}

int main() {
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s[0] >= '0' && s[0] <= '9') ans += int (get (s) < 18); else ans += check (s);
    }   
    cout << ans << endl;
    return 0;
}