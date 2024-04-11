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

const int N = 1e5 + 5;

int n;
int a[N];
int ans = 1e9, pas;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int t = 1; t <= 200; t++){
        int p = 0;
        for (int i = 1; i <= n; i++){
            if (a[i] == t)
                continue;
            p += min (abs (a[i] - (t - 1)), abs (a[i] - (t + 1)));
        }
        if (p < ans){
            ans = p;
            pas = t;
        }
    }
    cout << pas << " " << ans << endl;
    return 0;
}