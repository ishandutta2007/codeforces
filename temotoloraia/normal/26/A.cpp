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

int A[3005];

int f (int x){
    if (A[x])
        return A[x];
    if (x == 1)
        return 0;
    for (int i = 2; i * i <= x; i++){
        if (x % i == 0){
            int t = x;
            while (x % i == 0)
                x /= i;
            return A[t] = f(x) + 1;
        }
    }
    return A[x] = 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (f (i) == 2)
            ans++;
    cout << ans << endl;
    return 0;
}