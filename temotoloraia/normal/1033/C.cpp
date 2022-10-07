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
const int N = 1e5 + 5;
int n, a[N], b[N];
int F[N];
int main()
{
    #ifdef temo
    freopen  ("in.in", "r", stdin);
    freopen  ("out.out", "w", stdout);
    #endif // temo
    cin>>n;
    for (int i = 1; i <= n; i++)
        cin>>a[i];
    for (int i = 1; i <= n; i++)
        b[a[i]] = i;
    for (int i = n - 1; i >= 1; i--){
        F[i] = 0;
        for (int j = (b[i] - 1) % i + 1; j <= n; j += i)
            if (a[j] > i)
                F[i] = max (F[i], 1 - F[a[j]]);
    }
    for (int i = 1; i <= n; i++){
        char ch = 'A' + 1 - F[a[i]];
        cout<<ch;
    }
    cout<<endl;
    return 0;
}