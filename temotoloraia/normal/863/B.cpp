#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define LL long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;
const int MAXN = 100;
int n;
int a[MAXN + 5];
int b[MAXN + 5];
int main()
{
    cin>>n;
    n *= 2;
    for (int i = 1; i <= n; i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    int ans = 1e9;
    for (int A = 1; A <= n; A++)
        for (int B = A + 1; B <= n; B++){
            int x = 0, pas = 0, y = 1;
            for (int i = 1; i <= n; i++)
                if (i != A && i != B){
                    if (x == 0){
                        x = a[i];
                        continue;
                    }
                    if (y)
                    pas += abs (a[i] - x);
                    y^=1;
                    x = a[i];
                }
            ans = min (ans, pas);
        }
    cout<<ans<<endl;
    return 0;
}