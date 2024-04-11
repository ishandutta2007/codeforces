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

const int N = 1234567;

int n, m;
int a[N];
int l[N], r[N], ans[N];

vector < int > v[N];

int mas[N];
map < int, int > M;

void update (int x, int y){
    for (int i = x; i <= n; i = i * 2 - (i & (i - 1)))
        mas[i] = min (mas[i], y);
}

int datvla (int x){
    int pas = n + 100;
    for (int i = x; i > 0; i = (i & (i - 1)))
        pas = min (pas, mas[i]);
    return pas;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++){
        cin >> l[i] >> r[i];
        v[l[i]].pb (i);
    }
    for (int i = 1; i <= n; i++)
        mas[i] = n + 100;
    for (int i = n; i >= 1; i--){
        int t = M[a[i]];
        if (t != 0){
            update (t, t - i);
        }
        M[a[i]] = i;
        for (int j : v[i]){
            ans[j] = datvla (r[j]);
            if (ans[j] > n)
                ans[j] = -1;
        }
    }
    for (int i = 1; i <= m; i++)
        cout << ans[i] << endl;
    return 0;
}