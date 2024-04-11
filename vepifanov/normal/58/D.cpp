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
string s[10000];
string w;
int l[10000];
set<pair<string, int> > LEFT, RIGHT[11];

int main() {
    cin >> n;
    int sum = n / 2;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        sum += sz (s[i]);
    }   
    sum /= (n / 2);
    cin >> w;   
    for (int i = 0; i < n; i++) {
        l[i] = sz (s[i]);
        RIGHT[l[i]].insert (mp (s[i], i));
        LEFT.insert (mp (s[i] + w, i));
    }
    for (int i = 0; i * 2 < n; i++) {
        int j = LEFT.begin ()->se;
        LEFT.erase (LEFT.begin ());
        RIGHT[l[j]].erase (mp (s[j], j));
        int rem = sum - l[j] - 1;
        int k = RIGHT[rem].begin ()->se;
        RIGHT[rem].erase (RIGHT[rem].begin ());
        LEFT.erase (mp (s[k] + w, k));
        cout << s[j] + w + s[k] << endl;
    }
    return 0;
}