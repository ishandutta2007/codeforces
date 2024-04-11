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
const int N = 100005;
int n, a[N];
int S[N];
int ans = 33333;
main() {
    cin>>n;
    for (int i = 1; i <= n; i++){
        cin>>a[i];
        S[i] = S[i - 1] + a[i];
        a[n + i] = a[i];
    }
    for (int i = n + 1; i <= n * 2; i++)
        S[i] = S[i - 1] + a[i];
    for (int i = 0; i <= n * 2; i++)
        for (int j = i; j <= n * 2; j++)
            ans = min (ans, abs (S[j] - S[i] - 180));
    cout<<ans * 2<<endl;
    return 0;
}