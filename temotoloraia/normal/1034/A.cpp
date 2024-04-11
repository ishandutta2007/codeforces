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
const ll N = 3e5 + 5, M = 15e6;
int S[M + 5];
int A[M + 5];
int n;
int a[N], x, t;
int main()
{
    //freopen ("in.in", "r", stdin);
    //freopen ("out.out", "w", stdout);
    for (int i = 2; i * i <= M; i++)
        if (S[i] == 0){
            S[i] = i;
            for (int j = i * i; j <= M; j += i)
                S[j] = i;
        }
    for (int i = 1; i <= M; i++)
        if (S[i] == 0)
            S[i] = i;
    cin>>n;
    for (int i = 1; i <= n; i++){
        cin>>a[i];
        if (i == 1)
            x = a[i];
        else
            x = __gcd (x, a[i]);
    }
    for (int i = 1; i <= n; i++)
        a[i] /= x;
    for (int i = 1; i <= n; i++){
        x = a[i];
        while (x > 1){
            A[S[x]]++;
            t = S[x];
            while (x % t == 0)
                x /= t;
        }
    }
    int ans = n;
    for (int i = 2; i <= M; i++)
        ans = min (ans, n - A[i]);
    if (ans == n)
        ans = -1;
    cout<<ans<<endl;
    return 0;
}