#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ll long long int
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;
const int MAXN = 200000;
int n;
int a[100][100];
bool F[5];
bool fix[1000000];
int main()
{
    cin>>n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 6; j++)
            cin>>a[i][j];
    int m = n * 6;
    if (n >= 3){
    for (int x = 0; x < m; x++){
        F[x / 6] = 1;
        for (int y = 0; y < m; y++){
            if (F[y / 6])
                continue;
            F[y / 6] = 1;
            for (int z = 0; z < m; z++){
                if (F[z / 6])
                    continue;
                fix[a[x / 6][x % 6] * 100 + a[y / 6][y % 6] * 10 + a[z / 6][z % 6]] = 1;
            }
            F[y / 6] = 0;
        }
        F[x / 6] = 0;
    }
    }
    if (n >= 2){
        for (int x = 0; x < m; x++){
            F[x / 6] = 1;
            for (int y = 0; y < m; y++){
                if (F[y / 6])
                    continue;
                fix[a[x / 6][x % 6] * 10 + a[y / 6][y % 6]] = 1;
            }
            F[x / 6] = 0;
        }
    }
    if (n >= 1){
        for (int x = 0; x < m; x++)
            fix[a[x / 6][x % 6]] = 1;
    }
    int ans = 0;
    for (int i = 1; i <= 1000; i++)
        if (fix[i] == 0){
            ans = i - 1;
            break;
        }
    cout<<ans<<endl;
    return 0;
}