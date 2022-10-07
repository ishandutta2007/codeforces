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
const int N = 1e5 + 7;

int n, m;
int a[N];
int b[N];

int main()
{
    cin>>n>>m;
    int ans = n + m;
    for (int i = 1; i <= n; i++)
        cin>>a[i];
    sort (a + 1, a + n + 1);
    a[++n] = 1e9;
    while (m--){
        int x, y, z;
        cin>>x>>y>>z;
        if (x != 1)
            continue;
        int I = 0;
        for (int i = 19; i >= 0; i--){
            if (I + (1<<i) > n)
                continue;
            if (a[I + (1<<i)] <= y)
                I += (1<<i);
        }
        b[I]++;
    }
    for (int i = n; i >= 1; i--)
        b[i] += b[i + 1];
    for (int i = 1; i <= n; i++)
        ans = min (ans, i - 1 + b[i]);
    cout<<ans<<endl;
    return 0;
}