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
//#define temo

using namespace std;
const int N = 3e5 + 7;

int n;
int x[N], y[N];
int X1[N], X2[N], Y1[N], Y2[N];
pair < int, int > P[N];
int ans;

int main()
{
    cin>>n;
    for (int i = 1; i <= n; i++){
        scanf ("%d%d", &x[i], &y[i]);
        P[i] = {x[i], y[i]};
    }
    sort (P + 1, P + n + 1);
    for (int i = 1; i <= n; i++){
        x[i] = P[i].F;
        y[i] = P[i].S;
    }
    X1[1] = y[1];
    X2[1] = y[1];
    for (int i = 2; i <= n; i++){
        X1[i] = min (X1[i - 1], y[i]);
        X2[i] = max (X2[i - 1], y[i]);
    }
    Y1[n] = y[n];
    Y2[n] = y[n];
    for (int i = n - 1; i >= 1; i--){
        Y1[i] = min (Y1[i + 1], y[i]);
        Y2[i] = max (Y2[i + 1], y[i]);
    }
    for (int i = 1; i <= n - 2; i++){
        ans = max (ans, Y2[i + 1] + x[n] - x[i] - y[i]);
        ans = max (ans, x[n] - x[i] + y[i] - Y1[i + 1]);
    }
    for (int i = n; i >= 3; i--){
        ans = max (ans, X2[i - 1] + x[i] - x[1] - y[i]);
        ans = max (ans, x[i] - x[1] + y[i] - X1[i - 1]);
    }
    cout<<ans * 2<<" ";
    ans = 2 * (x[n] - x[1] + X2[n] - X1[n]);
    for (int i = 4; i <= n; i++)
        printf ("%d ", ans);
    return 0;
}