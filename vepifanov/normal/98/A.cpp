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

const int A[6] = {1, 2, 3, 0, 4, 5};
const int B[6] = {5, 1, 4, 3, 0, 2};
const int C[6] = {0, 5, 2, 4, 1, 3};

int n;
int m;
string s;

set<string> all;
int p[6], q[6];

string get (string s) {
    for (int i = 0; i < 6; i++) p[i] = i;
    string w = s;
    for (int a = 0; a < 4; a++) {
        for (int b = 0; b < 4; b++) {
            for (int c = 0; c < 4; c++) {
                string t = "";
                for (int j = 0; j < 6; j++) t += s[p[j]];
                w = min (w, t);
                for (int j = 0; j < 6; j++) q[C[j]] = p[j];
                for (int j = 0; j < 6; j++) p[j] = q[j];
            }   
            for (int j = 0; j < 6; j++) q[B[j]] = p[j];
            for (int j = 0; j < 6; j++) p[j] = q[j];
        }   
        for (int j = 0; j < 6; j++) q[A[j]] = p[j];
        for (int j = 0; j < 6; j++) p[j] = q[j];
    }
    re w;
}

int main () {
    cin >> s;
    sort (all (s));
    do {    
        all.insert (get (s));
    } while (next_permutation (all (s)));
    printf ("%d\n", sz (all));
    return 0;
}