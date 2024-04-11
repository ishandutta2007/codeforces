#include<algorithm>
#include<iostream>
#include<numeric>
#include<vector>
#include<string>
#include<queue>
#include<cmath>
#include<map>
#include<set>

using namespace std;

#define FOR(i,a,b)  for(int i(a);i<(b);++i)
#define REP(i,n)    FOR(i,0,n)
#define SORT(a)     sort((a).begin(),(a).end())
#define UN(a)       SORT(a),(a).erase(unique((a).begin(),(a).end()),(a).end())
#define CL(a)       memset(a,b,sizeof a)
#define pb          push_back

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

#define X first
#define Y second

int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};
int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};

string dd[8] = {"L", "R", "U", "D", "LU", "LD", "RU", "RD"};

pii parse (string s)
{
    return pii (s[0]-'a', 7-(s[1]-'1'));
}

int main() {
    #ifdef LOCAL
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    string q, w;
    cin >> q >> w;
    pii a = parse (q);
    pii b = parse (w);
    int _t1, _t2, _l1, _l2;
    int res = 10000;
    REP (t1, 8)
        REP (t2, 8)
            REP (l1, 9)
                REP (l2, 9)
                {
                    int y = a.Y;
                    int x = a.X;
                    REP (k, l1)
                    {
                        y += dy[t1];
                        x += dx[t1];
                        if (y < 0 || x < 0 || y >= 8 || x >= 8)
                            goto nah;
                    }
                    REP (k, l2)
                    {
                        y += dy[t2];
                        x += dx[t2];
                        if (y < 0 || x < 0 || y >= 8 || x >= 8)
                            goto nah;
                    }
                    if (y == b.Y && x == b.X)
                    {
                        if (res > l1+l2)
                        {
                            res = l1+l2;
                            _t1 = t1;
                            _t2 = t2;
                            _l1 = l1;
                            _l2 = l2;
                        }                        
                    }
nah:;
                }
    cout << _l1+_l2 << endl;
    REP (i, _l1)
        cout << dd[_t1] << endl;
    REP (i, _l2)
        cout << dd[_t2] << endl;

	return 0;
}