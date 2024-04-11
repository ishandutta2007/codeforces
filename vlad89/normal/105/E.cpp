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

int move[3], kick[3];

int maxpos;

set<long long> was;
int best;

void solve(int mask, int pos[3], int grab[3]) {
    int maxpos = max (max (pos[0], pos[1]), pos[2]);
    if (maxpos > best)
	best = maxpos;
    if (pos[0] < 0 || pos[1] < 0 || pos[2] < 0) return;
    
    long long code = (((((mask * 512LL + pos[0]) * 70 + pos[1]) * 70 + pos[2]) * 70 + grab[0]) * 4 + grab[1]) * 4 + grab[2];
    if (was.count(code)) return;
    was.insert(code);
    int Pos[3], Grab[3];
    REP (who, 3) {
	if (grab[0] == who+1 || grab[1] == who+1 || grab[2] == who+1) continue;
	if (grab[who] == 0 && !(mask & (1 << (3 * who)))) {
	    FOR(p, pos[who]-move[who], pos[who]+move[who]+1) {
		if (pos[0] != p && pos[1] != p && pos[2] != p) {
		    REP (g, 3) Pos[g] = pos[g], Grab[g] = grab[g];
		    Pos[who] = p;
		    solve(mask | (1 << (3 * who)), Pos, Grab);
		}
	    }		
	}
	if (grab[who] == 0 && !(mask & (1 << (3 * who + 1)))) {
	    REP (take, 3) {
		if (abs (pos[take] - pos[who]) != 1) continue;
		REP (g, 3) Pos[g] = pos[g], Grab[g] = grab[g];
		Pos[take] = Pos[who];
		Grab[who] = take+1;
		solve(mask | (1 << (3 * who + 1)), Pos, Grab);
	    }
	}
	if (grab[who] != 0 && !(mask & (1 << (3 * who + 2)))) {
	    FOR(p, pos[who]-kick[who], pos[who]+kick[who]+1) {
		if (pos[0] != p && pos[1] != p && pos[2] != p) {
		    REP (g, 3) Pos[g] = pos[g], Grab[g] = grab[g];
		    Pos[grab[who]-1] = p;
		    if (grab[grab[who]-1] != 0) {
			Pos[grab[grab[who]-1]-1] = p;
		    }
		    Grab[who] = 0;
		    solve(mask | (1 << (3 * who + 2)), Pos, Grab);
		}
	    }
	}
    }
}

int main () {
#ifdef LocalHost
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    int pos[3];
    int grab[3] = {0, 0, 0};
    REP (i, 3) {
	cin >> pos[i] >> move[i] >> kick[i];
	pos[i] += 5;
    }
    solve (0, pos, grab);
    cout << best-5 << endl;
    return 0;
}