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
char w[300];

int main() {
    gets (w);
    string s (w);
    for (int i = 0; i < sz (s); i++)
        while (i + 1 < sz (s) && s[i] == ' ' && s[i + 1] == ' ') s.erase (i, 1);
    for (int i = 1; i + 1 < sz (s); i++)
        if (s[i] == ' ')
            if (!(s[i - 1] >= '0' && s[i - 1] <= '9') || !(s[i + 1] >= '0' && s[i + 1] <= '9'))
                s.erase (i, 1);
    for (int i = 0; i < sz (s); i++)
        if (s[i] != ' ') {
            int space = 0;
            if (i > 0) {
                if (s[i - 1] == ',') space = 1;
                if (s[i] >= '0' && s[i] <= '9') {
                    if (s[i - 1] == ' ') space = 1;
                }
                if (s[i] == '.') {
                    if (s[i - 1] == 'a') s[i] = 'b'; else
                    if (s[i - 1] == 'b') s[i] = 'c'; else {
                        s[i] = 'a';
                        space = 1;
                    }   
                }
                }
            if (space) printf (" ");
            if (i == 0 && s[i] == '.') s[i] = 'a';
            if (s[i] == 'a' || s[i] == 'b' || s[i] == 'c') printf ("."); else printf ("%c", s[i]);
        }
    printf ("\n");  
    return 0;
}