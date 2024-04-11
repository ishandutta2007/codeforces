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

const int N = 1005;

int n, m;
int a[N][N];
int p[N][N], q[N][N];

int mas[N];
int x[N], y[N];
map < int, int > M;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++)
            mas[j] = a[i][j];
        sort (mas + 1, mas + m + 1);
        int t = 0;
        M.clear();
        for (int j = 1; j <= m; j++){
            if (mas[j] > mas[j - 1])
                t++;
            M[mas[j]] = t;
        }
        x[i] = t;
        for (int j = 1; j <= m; j++)
            p[i][j] = M[a[i][j]];
    }
    for (int j = 1; j <= m; j++){
        for (int i = 1; i <= n; i++)
            mas[i] = a[i][j];
        sort (mas + 1, mas + n + 1);
        int t = 0;
        M.clear();
        for (int i = 1; i <= n; i++){
            if (mas[i] > mas[i - 1])
                t++;
            M[mas[i]] = t;
        }
        y[j] = t;
        for (int i = 1; i <= n; i++)
            q[i][j] = M[a[i][j]];
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            int t = max (p[i][j], q[i][j]);
            cout << max (x[i] + t - p[i][j], y[j] + t - q[i][j]) << " ";
        }
        cout << endl;
    }
    return 0;
}