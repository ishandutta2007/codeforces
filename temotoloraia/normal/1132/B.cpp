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

const int N = 2100000;

int n;
ll a[N];
ll S;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort (a + 1, a + n + 1);
    reverse (a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        S += a[i];
    int m;
    cin >> m;
    while (m--){
        int x;
        cin >> x;
        cout << S - a[x] << endl;
    }
    return 0;
}