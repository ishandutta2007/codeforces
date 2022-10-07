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
using namespace std;

const ll N = 1e6 + 5;
int n;

vector < pair < double, double > > P;
vector < double > a, b;

pair < pair < double, double >, int > p, q, t;

stack < pair < pair < double, double >, int > > S;
// y = ax + b

int mas[N];
int nn;

map < pair < double, double >, int > M;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++){
        double x, y;
        cin >> x >> y;
        P.pb ({-x, y - x * x});
        //cout << -x << "       " << y - x * x << endl;
    }
    //cout << endl << endl;
    sort (P.begin(), P.end());
    for (int i = 0; i < n; i++){
        a.pb (P[i].F);
        b.pb (P[i].S);
        //cout << a[i] << " " << b[i] << endl;
    }
    for (int i = 0; i < n; i++){
        while ((int)S.size() >= 1){
            p = S.top();
            if (p.F.F != a[i])
                break;
            S.pop();
        }
        while ((int)S.size() >= 2){
            p = S.top();
            S.pop();
            q = S.top();
            double x = (p.F.S - q.F.S) / (q.F.F - p.F.F);
            double y = p.F.S + x * p.F.F;
            S.push (p);
            if (a[i] * x + b[i] >= y)
                S.pop();
            else
                break;
        }
        S.push({{a[i], b[i]}, i});
    }
    while ((int)S.size() > 0){
        mas[++nn] = S.top().S;
        S.pop();
    }
    //cout << nn << endl;
    reverse (mas + 1, mas + nn + 1);
    int ans = 0;
    for (int i = 1; i < nn; i++){
        double x = (b[mas[i + 1]] - b[mas[i]]) / (a[mas[i]] - a[mas[i + 1]]);
        double y = a[mas[i]] * x + b[mas[i]];
        M[{x, y}]++;
        //cout << a[mas[i]] << " " << b[mas[i]] << " " << a[mas[i + 1]] << " " << b[mas[i + 1]] << endl;
        if (M[{x, y}] == 1)
            ans++;
    }
    cout << ans << endl;
    return 0;
}