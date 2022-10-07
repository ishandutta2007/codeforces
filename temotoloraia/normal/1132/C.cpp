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

const int N = 6000;

int n, m;

int l[N], r[N];
int a[N];

int mas[N][5];

int ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> l[i] >> r[i];
    for (int i = 1; i <= m; i++){
        a[l[i]]++;
        a[r[i] + 1]--;
    }
    for (int i = 1; i <= n; i++)
        a[i] += a[i - 1];
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= 3; j++)
            mas[i][j] = mas[i - 1][j];
        for (int j = 1; j <= 3; j++)
            if (a[i] >= j)
                mas[i][j]++;
    }
    for (int i = 1; i <= m; i++)
        for (int j = i + 1; j <= m; j++){
            int x = l[i], y = r[i];
            int L = l[j], R = r[j];
            if (x > L){
                swap (x, L);
                swap (y, R);
            }
            int pas = 0;
            if (y < L){
                pas = mas[x - 1][1] + (mas[y][2] - mas[x - 1][2]) + (mas[L - 1][1] - mas[y][1]) + (mas[R][2] - mas[L - 1][2]) + (mas[n][1] - mas[R][1]);
                //     1  x - 1                x   y                          y + 1      L - 1           L     R                   R + 1     n
            }
            else {
                if (y > R)
                    swap (y, R);
            pas = mas[x - 1][1] + (mas[L - 1][2] - mas[x - 1][2]) + (mas[y][3] - mas[L - 1][3]) + (mas[R][2] - mas[y][2]) + (mas[n][1] - mas[R][1]);
            //     1  x - 1    1        x   L - 1    2                 L   y   3                     y + 1     R   2             R + 1     n  1
            }
            ans = max (ans, pas);
        }
    cout << ans << endl;
    return 0;
}