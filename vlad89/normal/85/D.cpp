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
#define UN(a) sort(all(a)),(a).resize(unique(all(a))-a.begin())
#define sz(a) ((int) (a).size())
#define pb push_back
#define CL(a,b) memset (a, b, sizeof (a))
#define X first
#define Y second

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

const int M = 1<<17;
vector<int> op;
vector<int> order;
long long S[1<<18][5];
int C[1<<18];
int n;

int main() {
    #ifdef LocalHost
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    scanf ("%d", &n);
    char ss[8];
    int num;
    REP (i, n) {
        scanf ("%s", ss);
        if (ss[0] == 's')
            op.pb(0);
        else {
            scanf ("%d", &num);
            order.pb(num);            
            if (ss[0] == 'a') {
                op.pb(num);
            } else {
                op.pb(-num);
            }            
        }
    }
    UN(order);
    REP (i, sz (op)) {
        if (op[i] == 0) {
            cout << S[0][2] << endl;
        } else {
            int num = abs(op[i]);
            num = lower_bound(all(order), num)-order.begin();
            
            int x = M-1+num;            
            if (op[i] > 0) {
                C[x]++;
                S[x][0]+=order[num];
            } else {
                C[x]--;
                S[x][0]-=order[num];
            }
            while (x) {
                x = (x-1)/2;
                C[x] = C[x*2+1]+C[x*2+2];
                REP (j, 5) {
                    S[x][j] = S[x*2+1][j] + S[x*2+2][((j-C[x*2+1])%5+5)%5];
                }                    
            }
        }
    }
	return 0;
}