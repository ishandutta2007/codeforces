#define _CRT_SECURE_NO_DEPRECATE
#include <functional>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <sstream>
#include <numeric>
#include <cstdlib>
#include <cstdio>
#include <bitset>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
#include <list>
#include <set>
#include <map>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define all(a) (a).begin(),(a).end()
#define UN(a) SORT(a),(a).resize(unique(all(a))-a.begin())
#define sz(a) ((int) (a).size())
#define pb push_back
#define CL(a,b) memset (a, b, sizeof (a))
#define X first
#define Y second

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

int n;
char res[4][128];

int main() {
    #ifdef LocalHost
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    cin >> n;
    if (n % 2 == 0) {
        REP (i, n/2) {
            char c = (i%2)+'a';
            res[0][i*2] = c;
            res[0][i*2+1] = c;
            res[3][i*2] = c;
            res[3][i*2+1] = c;
            
            if (i < n/2-1) {
                res[1][i*2+1] = c+5;
                res[1][i*2+2] = c+5;
                res[2][i*2+1] = c+7;
                res[2][i*2+2] = c+7;
            }
        }        
        res[1][0] = 'c';
        res[2][0] = 'c';
        
        res[1][n-1] = 'd';
        res[2][n-1] = 'd';        
    } else {
        REP (i, n/2) {
            char c = (i%2)+'a';
            res[0][i*2] = c;
            res[0][i*2+1] = c;
            res[1][i*2] = c+2;
            res[1][i*2+1] = c+2;
            
            res[2][i*2+1] = c+4;
            res[2][i*2+2] = c+4;
            res[3][i*2+1] = c+6;
            res[3][i*2+2] = c+6;            
        }
        res[0][n-1] = 'z';
        res[1][n-1] = 'z';
        res[2][0] = 'x';
        res[3][0] = 'x';        
    }
    REP (i, 4)
        cout << res[i] << endl; 
	return 0;
}