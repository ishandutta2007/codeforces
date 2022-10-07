#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ll long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define l1 l1228
#define l2 l2228
#define r1 r1228
#define r2 r2228
#define x1 x1228
#define y1 y1228
using namespace std;

const int N = 1e6 + 5;

int n, m;
vector < int > v[N];
set < pair < int, int > > S;
set < pair < int, int > >::iterator I;

int main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin >> n;
    while (n--){
        int a;
        cin >> a;
        I = S.lower_bound ({a, 0});
        if (I == S.begin()){
            m++;
            v[m].pb (a);
            S.insert ({a, m});
            continue;
        }
        I--;
        int k = (*I).S;
        S.erase (I);
        S.insert ({a, k});
        v[k].pb (a);
    }
    for (int i = 1; i <= m; i++){
        for (int j = 0; j < (int)v[i].size(); j++)
            cout << v[i][j] << " ";
        cout << endl;
    }
    return 0;
}