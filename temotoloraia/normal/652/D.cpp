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

const int N = 512345;

int n;
pair < pair < int, int >, int > P[N];
int ans[N], mas[N];

map < int, int > M;

void update (int x, int y){
    for (int i = x; i <= n + n; i = i * 2 - (i & (i - 1)))
        mas[i] += y;
}

int datvla (int x){
    int pas = 0;
    for (int i = x; i > 0; i = (i & (i - 1)))
        pas += mas[i];
    return pas;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> P[i].F.F >> P[i].F.S;
        P[i].S = i;
        ans[i] = P[i].F.F;
        ans[i + n] = P[i].F.S;
    }
    sort (ans + 1, ans + n + n + 1);
    M[ans[1]] = 1;
    for (int i = 2; i <= n + n; i++)
        if (ans[i] > ans[i - 1])
            M[ans[i]] = M[ans[i - 1]] + 1;
    for (int i = 1; i <= n; i++){
        P[i].F.F = M[P[i].F.F];
        P[i].F.S = M[P[i].F.S];
    }
    sort (P + 1, P + n + 1);
    reverse (P + 1, P + n + 1);
    for (int i = 1; i <= n + n; i++)
        ans[i] = 0;
    for (int i = 1; i <= n; i++){
        ans[P[i].S] = datvla (P[i].F.S);
        update (P[i].F.S, 1);
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << endl;
    return 0;
}