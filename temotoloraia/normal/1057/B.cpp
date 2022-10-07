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
const int N = 2e5 + 5;

int n, a[N], ans;

int main()
{
    cin>>n;
    for (int i = 1; i <= n; i++)
        cin>>a[i];
    for (int i = 1; i <= n; i++){
        int s = 0;
        for (int j = i; j <= n; j++){
            s += a[j];
            if (s > 100 * (j - i + 1))
                ans = max (ans, j - i + 1);
        }
    }
    cout<<ans<<endl;
    return 0;
}