#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define all(a) (a).begin(),(a).end()
#define UN(a) sort(all(a)),(a).resize(unique(all(a))-(a).begin())
#define sz(a) ((int) (a).size())
#define pb push_back
#define CL(a,b) memset ((a), (b), sizeof (a))
#define X first
#define Y second

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

char s1[12345];
char s2[1234567];
int pos[26];
int next[12345][26];

int main () {
    #ifdef LOCAL
    	freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    gets(s1);
    gets(s2);
    int n = strlen(s1);
    int m = strlen(s2);
    CL (pos, -1);
    for (int i = n-1; i >= 0; --i)
        pos[s1[i]-'a'] = i;
    for (int i = n-1; i >= 0; --i) {
        pos[s1[i]-'a'] = i;
        REP (j, 26)
            next[i][j] = pos[j];                
    }
    int g = 0;
    int res = 1;
    REP (i, m) {
        int x = s2[i]-'a';
        if (next[g][x] == -1) {
            printf("-1\n");
            return 0;
        }
        if (next[g][x] < g)
            ++res;
        g = next[g][x];        
        g++;
        if (g == n && i != m-1) {
            ++res;
            g = 0;
        }
    }
    printf("%d\n", res);
    return 0;
}