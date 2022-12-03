#include <iostream>
#include <cstdio>
#include <bitset>
#include <cstring>
#include <sstream>
#include <vector>
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
#define ALL(a) (a).begin(),a.end()
#define SORT(a) sort(ALL(a))
#define UNIQUE(a) SORT(a),(a).resize(unique(ALL(a))-a.begin())
#define SZ(a) ((int) a.size())
#define pb push_back

#define VAR(a,b) __typeof(b) a=(b)
#define FORE(it,a) for(VAR(it,(a).begin());it!=(a).end();it++)
#define X first
#define Y second
#define DEBUG(x) cout << #x << " = " << x << endl;

#define INF 1000000000

typedef vector<int> VI;
typedef vector< vector<int> > VVI;
typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef long long ll;

string s[128];
string name[128];

char tmp[128];

bool checked[128];
bool cruel[128];
bool any[128];

bool check (int x)
{
    if (checked[x])
        return true;
    checked[x] = true;
    int i = 0;
    vector <string> tokens;
    while (i < SZ (s[x]))
    {
        if (s[x][i] == ' ')         
            ++i;
        else
        if (isalnum (s[x][i]))
        {
            string t;
            while (isalnum (s[x][i]))
            {
                t += s[x][i];
                ++i;
            }
            tokens.pb (t);
        } else
        {
            tokens.pb (string (1, s[x][i]));
            ++i;
        }
    }
    int open = 0;
    REP (i, SZ (tokens))
    {
        if (tokens[i] == "(")
            ++open;
        if (tokens[i] == ")")
            --open;
        if (open == 0 && (tokens[i] == "+" || tokens[i] == "-"))
            cruel[x] = true;
        if (open == 0 && (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"))
            any[x] = true;
        if (isalpha (tokens[i][0]))
        {
            int u = find (name, name + x, tokens[i]) - name;
            if (u == x)
                continue;
            if (!check (u)) return false;
            
            if (cruel[u])
            {
                if (i && (tokens[i-1] == "-" || tokens[i-1] == "*"))
                    return false;
                if (i != SZ (tokens) - 1 && (tokens[i+1] == "*" || tokens[i+1] == "/"))
                    return false;                 
                cruel[x] = true;
            }
            if (any[u])
            {
                if (i && (tokens[i-1] == "/"))
                    return false;
                any[x] = true;
            }
        }
    }
    return true;
}

int main() {
    #ifdef LOCAL
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    gets (tmp);
    int n;
    sscanf (tmp, "%d", &n);
    REP (i, n)
    {
        gets (tmp);
        s[i] = (string) tmp;
        int j = 0;
        int k = 0;
        while (k != 7)
        {
            k += (s[i][j] != ' ');
            ++j;
        }
        while (s[i][j] == ' ')
            ++j;
        while (isalpha (s[i][j]))
        {
            name[i] += s[i][j];
            ++j;
        }
        s[i] = s[i].substr (j);
    }
    gets (tmp);
    s[n] = (string) tmp;
    
    if (check (n))
        cout << "OK\n";
    else
        cout << "Suspicious\n";
	return 0;
}