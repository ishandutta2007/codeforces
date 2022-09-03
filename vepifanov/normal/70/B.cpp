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
char s[20000];

int main() {
    scanf ("%d", &n);
    gets (s);
    gets (s);
    int len = 0;
    int cur = 0, ans = 1;
    for (int i = 0; s[i]; i++) {
        len++;
        if (s[i] == '.' || s[i] == '?' || s[i] == '!') { 
            if (len > n) {
                printf ("Impossible\n");
                re 0;
            }
            if (int (cur > 0) + cur + len > n) { cur = 0; ans++; }
            cur += len + int (cur > 0);
            len = -1;
        }
    }   
    printf ("%d\n", ans);
    return 0;
}