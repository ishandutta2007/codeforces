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
int n, x, k;
int a[N];
ll ans;
map < int, ll > M;
main() {
    cin>>n>>x>>k;
    for (int i = 1; i <= n; i++)
        cin>>a[i];
    sort (a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        M[(a[i] - 1) / x]++;
    for (int i = 1; i <= n; i++)
        ans += M[(a[i] / x) - k];
    for (int i = 1; i <= n; i++)
        M[(a[i] - 1) / x]--;
    if (k == 0){
        ll p = 0;
        for (int i = 1; i <= n; i++){
            if (a[i] == a[i - 1])
                p++;
            else {
                ans -= p * M[(a[i - 1] - 1) / x];
                M[a[i - 1] / x] += p;
                p = 1;
            }
        }
        ans -= p * M[(a[n] - 1) / x];
    }
    cout<<ans<<endl;
    return 0;
}