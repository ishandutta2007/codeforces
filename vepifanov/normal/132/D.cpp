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

int res[1000001];

int main () {
    cin >> s;
    reverse (all (s));
    s += '0';
    int cur = 0;
    for (int i = 0; i < sz (s); i++)
        if (s[i] == '1') {
            int j = i;
            while (s[j] == '1') j++;
            if (j == i + 1) res[i] = 1; else {
                res[i] = -1;
                s[j] = '1';
                i = j - 1;
            }
        }
    int cnt = 0;
    for (int i = 0; i < sz (s); i++)
        cnt += abs (res[i]);
    printf ("%d\n", cnt);
    for (int i = 0; i < sz (s); i++)
        if (res[i] == 1)
            printf ("+2^%d\n", i);
        else
        if (res[i] == -1)   
            printf ("-2^%d\n", i);
    return 0;
}