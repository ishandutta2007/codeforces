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

const int N = 123456;

int n;
int a[N];
int D[N];

int Q;
int p[N], k[N], ans[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cin >> Q;
    for (int i = 1; i <= Q; i++){
        cin >> p[i] >> k[i];
        ans[i] = -1;
    }
    for (int I = 1; I <= 300 && I <= n; I++){
        for (int i = n; i >= 1; i--){
            if (i + I + a[i] > n)
                D[i] = 1;
            else
                D[i] = D[i + I + a[i]] + 1;
        }
        for (int i = 1; i <= Q; i++)
            if (k[i] == I)
                ans[i] = D[p[i]];
    }
    for (int i = 1; i <= Q; i++){
        if (ans[i] != -1){
            cout << ans[i] << endl;
            continue;
        }
        int x = p[i], y = 0;
        while (x <= n){
            x = x + a[x] + k[i];
            y++;
        }
        cout << y << endl;
    }
    return 0;
}