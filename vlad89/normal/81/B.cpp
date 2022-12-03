#include <iostream>
#include <cstring>
#include <bitset>
#include <cstdio>
#include <sstream>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <numeric>
#include <functional>
#include <string>
#include <cstdlib>
#include <cmath>
#include <list>

using namespace std;

#define FOR(i,a,b) for(int i=(a),_b(b);i<_b;++i)
#define FORD(i,a,b) for(int i=(a),_b(b);i>=_b;--i)
#define REP(i,n) FOR(i,0,n)
#define ALL(a) (a).begin(),(a).end()
#define UNIQUE(a) sort(ALL(a)),(a).resize(unique(ALL(a))-(a).begin())
#define sz(a) ((int) (a).size())
#define pb push_back

#define X first
#define Y second

typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef long long ll;

char s[512];

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    gets (s);
    int n = strlen(s);
    for (int i = 0; i < n; ) {
        if (isdigit (s[i]) && isdigit (s[i+1])) {
            printf ("%c", s[i]);
            ++i;
            continue;
        }
        char l = s[i];        
        if (s[i] == '.') {
            printf ("...");
            i += 3;
        } else {
            printf ("%c", s[i]);
            ++i;
        }
        int spaces = 0;
        while (s[i] == ' ') {
            ++spaces;
            ++i;
        }
        char r = s[i];
        if (!r)
            break;
        if ((isdigit (l) && isdigit (r)) || l == ',' || r == '.')
            spaces = 1;
        else
            spaces = 0;
        if (spaces)
            printf (" ");        
    }
    puts ("");
	return 0;
}