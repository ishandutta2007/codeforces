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
const int N = 200005;
int n, k;
int a[N], ans;
int main()
{
    #ifdef temo
    freopen  ("in.in", "r", stdin);
    freopen  ("out.out", "w", stdout);
    #endif temo
    cin>>n>>k;
    for (int i = 1; i <= n; i++)
        cin>>a[i];
    sort (a + 1, a + n + 1);
    int I = n, C = 0;
    for (int i = a[n]; i >= 1; i--){
        while (a[I] >= i)
            I--;
        if (C + n - I <= k && I > 0){
            C += n - I;
            continue;
        }
        if (C > 0)
        ans++;
        C = 0;
        C += n - I;
        if (I == 0)
            break;
    }
        cout<<ans<<endl;
    return 0;
}